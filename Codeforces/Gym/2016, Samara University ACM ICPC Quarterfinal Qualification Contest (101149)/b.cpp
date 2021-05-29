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

bool cmp(const pii &a, const pii &b){
    return (a.second - a.first) < (b.second - b.first);
}

int main(){
    optimize;

    int n;
    ll now = 0, ans = 0;

    cin >> n;

    vector<pii> v(n);
    
    for(int i = 0; i < n; i++)
        cin >> v[i].first >> v[i].second;
    
    sort(all(v), cmp);
    
    for(int i = 0; i < n; i++){
        if(v[i].first > now){
            ans += v[i].first - now;
            now = v[i].first;
        }
        now -= v[i].second;
    }

    cout << ans << "\n";

    return 0;   
}
