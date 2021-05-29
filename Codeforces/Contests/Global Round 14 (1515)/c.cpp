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
        
        int m, n, x;
        cin >> n >> m >> x;

        vector<pii> h(n);
        vector<int> ans(n);
        set<pii> s;

        for(int i = 0; i < n; i++){
            cin >> h[i].first;
            h[i].second = i;
        }

        sort(all(h));
        reverse(all(h));
        
        for(int i = 1; i <= m; i++)
            s.emplace(0, i);
        
        for(int i = 0; i < n; i++){
            
            pii p = *s.begin();
            s.erase(s.begin());
        
            ans[h[i].second] = p.second;
            p.first += h[i].first;

            s.insert(p);
        }

        if(s.rbegin()->first - s.begin()->first > x)
            cout << "NO" << "\n";
        else{
            cout << "YES" << "\n";
        
            for(int i = 0; i < n; i++)
                cout << ans[i] << " \n"[i==n-1];
        }
    }

    return 0;  
}
