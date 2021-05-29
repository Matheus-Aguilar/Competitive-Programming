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

using namespace std;

int binSearch(int l, int r, int n, int x){
    while(l < r){
        int m = l + (r - l)/2;
        if(n <= x * (m - 1) + 2)
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main(){
    optimize;
    
    int t;
    cin >> t;

    while(t--){
        int n, x;
        cin >> n >> x;
        cout << binSearch(1, 10000, n, x) << "\n";
    }

    return 0;   
}
