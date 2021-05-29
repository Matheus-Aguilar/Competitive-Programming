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

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n, d;
        ll k;
        cin >> n >> k;

        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        d = *max_element(all(a));
        for(int i = 0; i < n; i++)
            a[i] = d - a[i];
        
        if(k % 2 == 0){
            d = *max_element(all(a));
            for(int i = 0; i < n; i++)
                a[i] = d - a[i];
        }

        for(int i = 0; i < n; i++)
            cout << a[i] << " \n"[i==n-1];
    }
    
    return 0;   
}
