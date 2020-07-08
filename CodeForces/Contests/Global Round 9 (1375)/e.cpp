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
#define MAXN 1100
#define fi first
#define se second

using namespace std;

int a[MAXN];

bool cmp(const pii &x, const pii &y){
    if(x.se != y.se)
        return x.se > y.se;
    if(a[x.fi] != a[y.fi])
        return a[x.fi] < a[y.fi];
    return x.fi < y.fi;
}

int main(){
    optimize;
    
    int n;
    cin >> n;
    vector<pii> ans;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(a[i] > a[j])
                ans.emplace_back(i, j);
    sort(all(ans), cmp);
    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    return 0;   
}
