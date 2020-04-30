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
        vector<pii> p(n);
        for(int i = 0; i < n; i++)
            cin >> p[i].second >> p[i].first;
        p.emplace_back(0, 0);
        sort(all(p));

        bool ok = true;
        string ans = "";

        for(int i = 1; i <= n; i++){
            if(p[i - 1].second > p[i].second){
                ok = false;
                break;
            }
            for(int j = p[i - 1].second; j < p[i].second; j++){
                ans += 'R';
            }
            for(int j = p[i - 1].first; j < p[i].first; j++){
                ans += 'U';
            }
        }

        if(!ok)
            cout << "NO" << "\n";
        else
            cout << "YES" << "\n" << ans << "\n";
    }
    
    return 0;   
}
