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

    ll l;
    int m;

    cin >> l >> m;

    vector<string> s(m), ans;
    vector<ll> p(m), c(m), t(m), r(m);

    char aux;

    for(int i = 0; i < m; i++){
        cin.ignore();
        getline(cin, s[i], ',');
        cin >> p[i] >> aux >> c[i] >> aux >> t[i] >> aux >> r[i];
    }

    ll best = INFLL;

    for(int i = 0; i < m; i++){
        
        double steps = ((double) (l)) / (c[i] * t[i]);

        if(steps * (t[i] + r[i]) <= 10080){
            if(p[i] <= best){
                if(p[i] < best){
                    ans.clear();
                }
                ans.push_back(s[i]);
                best = min(best, p[i]);
            }
        }
    }

    if(ans.size() == 0)
        cout << "no such mower" << "\n";
    else{
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << "\n";
    }
    
    return 0;   
}
