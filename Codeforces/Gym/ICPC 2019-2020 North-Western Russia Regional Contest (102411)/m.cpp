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

        vector<int> a(n);
        vector<int> ord(n);
        vector<int> pos(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
            ord[i] = 2 * a[i];
        }
    
        sort(all(ord));
        ord.resize(unique(all(ord)) - ord.begin());

        for(int i = 0; i < n; i++){
            pos[i] = lower_bound(all(ord), 2 * a[i]) - ord.begin();
        }

        vector<vector<int>> cont(n + 1, vector<int>(ord.size(), 0));

        for(int i = 1; i <= n; i++){
            cont[i] = cont[i - 1];
            cont[i][pos[i - 1]]++;
        }

        ll ans = 0;

        for(int i = 0; i < n; i++){
            for(int k = i + 2; k < n; k++){
                int pos = lower_bound(all(ord), a[i] + a[k]) - ord.begin();
                if(pos < ord.size() && ord[pos] == a[i] + a[k]){
                    ans += cont[k][pos] - cont[i + 1][pos];
                }
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;   
}
