#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 1010

using namespace std;

int n, h[MAXN], v[MAXN];

bool check(int x){
    for(int i = 0; i < n; i++){
        if(h[i] + x > v[i])
            return true;
        if(h[i] + x < v[i])
            return false;
    }
    return true;
}

int binSearch(int l, int r){
    while(l < r){
        int m = l + (r - l) / 2;
        if(check(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main(){
    optimize;
    
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> h[i];
    
    for(int i = 0; i < n; i++)
        cin >> v[i];

    cout << binSearch(0, INF) << "\n";

    return 0;   
}
