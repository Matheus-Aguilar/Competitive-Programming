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

const ll m[2] = {1000000007, 1000000009};

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        
        int n;
        cin >> n;

        vector<ll> a(n);
        
        vector<pii> ij;
        vector<pii> xy;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        if(n == 1){
            cout << 0 << "\n";
            continue;
        }

        for(int i = 0; i < n - 1; i++){
            ij.emplace_back(i + 1, i + 2);
            xy.emplace_back(m[i % 2], min(a[i], a[i + 1]));

            a[i] = xy[i].first;
            a[i + 1] = xy[i].second;
        }
    
        cout << ij.size() << "\n";

        for(int i = 0; i < ij.size(); i++){
            cout << ij[i].first << " " << ij[i].second << " " << xy[i].first << " " << xy[i].second << "\n";
        }

        // for(int i = 0; i < n; i++)
        //     cerr << a[i] << " \n"[i==n-1];
    }
    
    return 0;   
}
