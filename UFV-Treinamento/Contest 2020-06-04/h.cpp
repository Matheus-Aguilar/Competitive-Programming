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
    cin >> n;

    vector<pii> v(n);

    map<pii, int> mxy;
    map<int, int> mx;
    map<int, int> my;


    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
        mxy[v[i]]++;
        mx[v[i].first]++;
        my[v[i].second]++;
    }

    ll ans = 0;

    for(int i = 0; i < n; i++)
        ans += mx[v[i].first] + my[v[i].second] - mxy[v[i]] - 1;

    cout << ans/2LL << "\n";

    return 0;   
}
