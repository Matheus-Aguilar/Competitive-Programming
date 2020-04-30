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
        vector<int> p(n + 1);
        vector<int> f(n + 1, 1);
        multiset<int> m;
        set<int> s;
        f[0] = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            p[x] = i + 1;
        }

        for(int i = 1; i <= n; i++){
            s.insert(i);
            m.insert(1);
        }

        bool ans = true;
        for(int i = 1; i <= n && ans; i++){
            if(*(m.rbegin()) != f[p[i]]){
                ans = false;
            }
            else{
                s.erase(p[i]);
                auto it = m.find(f[p[i]]);
                m.erase(it);
                auto nxt = s.lower_bound(p[i]);
                if(nxt != s.end()){
                    auto it2 = m.find(f[*nxt]);
                    m.erase(it2);
                    f[*nxt] += f[p[i]];
                    m.insert(f[*nxt]);
                }
            }
        }
        cout << (ans ? "Yes" : "No") << "\n";
    }
    
    return 0;   
}
