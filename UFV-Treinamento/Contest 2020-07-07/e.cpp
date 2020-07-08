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
    
    int n;
    ll ans = 0;
    cin >> n;
    vector<pii> p(n);
    set<pii> s;
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
        s.insert(p[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int x, y;
            if((p[i].first + p[j].first) % 2 == 0) 
                x = (p[i].first + p[j].first)/2;
            else
                continue;
            if((p[i].second + p[j].second) % 2 == 0) 
                y = (p[i].second + p[j].second)/2;
            else
                continue;
            if(s.find(pii(x, y)) != s.end())
                ans++;
        }
    }

    cout << ans << "\n";

    return 0;   
}
