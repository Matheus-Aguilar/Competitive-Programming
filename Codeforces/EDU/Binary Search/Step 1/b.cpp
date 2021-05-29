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
#define MAXN 100100

using namespace std;

int n, k, a[MAXN];

int upperBound(int x){
    
    int l = 0, r = n;
    
    while(l < r){

        int m = l + (r - l)/2;

        if(a[m] <= x)
            l = m + 1;
        else
            r = m;
    }

    return l;
}

int main(){
    optimize;
    
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    while(k--){
        int x;
        cin >> x;
        cout << upperBound(x) << "\n";
    }

    return 0;   
}
