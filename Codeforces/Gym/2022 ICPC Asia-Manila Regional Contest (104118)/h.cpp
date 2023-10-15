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
#define MAXN 200200

using namespace std;

int n, ans[MAXN], idx[MAXN];
ll x, a[MAXN], b[MAXN];

bool cmp(int x, int y){
    if(a[x] != a[y])
        return a[x] < a[y];
    return b[x] < b[y];
}

int main(){
    optimize;

    cin >> n >> x;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> b[i];
    
    iota(idx, idx + n, 0);
    sort(idx, idx + n, cmp);

    ll sum = 0;

    for(int i = 0; i < n; i++){
        sum += a[idx[i]];
        if(sum <= x)
            ans[idx[i]] = 1;
        else
            sum -= a[idx[i]];
    }

    set<pii> diff, in, out;

    for(int i = 0; i < n; i++){
        if(ans[i] == 1){
            diff.emplace(b[i] - a[i], i);
            in.emplace(a[i], i);
        } else {
            out.emplace(b[i], i);
        }
    }

    while(sum <= x && !in.empty()){
        if(out.empty() || diff.begin()->first <= out.begin()->first - in.rbegin()->first){
            
            sum += diff.begin()->first;
            if(sum > x)
                break;

            int i = diff.begin()->second;

            diff.erase(make_pair(b[i] - a[i], i));
            in.erase(make_pair(a[i], i));
            ans[i] = 2;
        } else {
            
            sum += out.begin()->first - in.rbegin()->first;
            if(sum > x)
                break;

            int i = in.rbegin()->second;
            int j = out.begin()->second;

            diff.erase(make_pair(b[i] - a[i], i));
            in.erase(make_pair(a[i], i));
            out.emplace(b[i], i);
            ans[i] = 0;

            out.erase(make_pair(b[j], j));
            ans[j] = 2;
        }
    }

    for(int i = 0; i < n; i++)
        cout << ans[i];

    cout << "\n";

    return 0;   
}
