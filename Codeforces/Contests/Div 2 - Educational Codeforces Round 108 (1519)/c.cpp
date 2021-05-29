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
        int n;
        cin >> n;

        vector<int> u(n);
        vector<ll> s(n);

        vector<vector<ll>> a(n);
        vector<ll> k(n, 0);

        for(int i = 0; i < n; i++)
            cin >> u[i];
        
        for(int i = 0; i < n; i++)
            cin >> s[i];
    
        for(int i = 0; i < n; i++)
            a[u[i] - 1].push_back(s[i]);
        
        for(int i = 0; i < n; i++){
            sort(all(a[i]));
        }

        for(int i = 0; i < n; i++){
            for(int j = 1; j < a[i].size(); j++){
                a[i][j] += a[i][j - 1];
            }
        }

        for(int i = 0; i < n; i++){

            int sz = a[i].size();

            for(int j = 1; j <= sz; j++){
                
                k[j - 1] += a[i][sz - 1];

                if(sz % j != 0){
                    k[j - 1] -= a[i][sz % j - 1];
                }

            }
        }

        for(int i = 0; i < n; i++)
            cout << k[i] << " \n"[i==n-1];
    }
    
    return 0;   
}
