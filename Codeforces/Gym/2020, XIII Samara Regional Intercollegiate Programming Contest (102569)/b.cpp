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

int n;
ll t;

int solve(vector<ll> &x){
    vector<ll> l, r;

    for(int i = 0; i < x.size(); i++){
        if(x[i] < 0)
            l.push_back(-x[i]);
        else
            r.push_back(x[i]);
    }

    reverse(all(l));

    int ans = 0;

    for(int i = 0; i < r.size() && r[i] <= t; i++){
        int cnt = i + 1;
        cnt += upper_bound(all(l), t - 2 * r[i]) - l.begin();
        ans = max(ans, cnt);
    }

    return ans;
}

int main(){
    optimize;

    cin >> n >> t;

    vector<ll> x1(n), x2(n);

    for(int i = 0; i < n; i++)
        cin >> x1[i];
    
    x2 = x1;

    for(int i = 0; i < n; i++)
        x2[i] *= -1;
    
    reverse(all(x2));

    cout << max(solve(x1), solve(x2)) << "\n";
    
    return 0;   
}
