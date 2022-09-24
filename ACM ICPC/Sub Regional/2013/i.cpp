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

int n, c, t1, t2;
vector<int> f;
vector<int> dp;
vector<int> s;

int solve(int i){
    if(i == n)
        return 0;
    if(dp[i] == -1){
        int nxt1 = lower_bound(all(s), s[i] + t1 + 1) - s.begin();
        int nxt2 = lower_bound(all(s), s[i] + t2 + 1) - s.begin();
        dp[i] = min(solve(nxt1) + t1, solve(nxt2) + t2);
    }
    return dp[i];
}

int main(){
    optimize;
    
    while(cin >> n >> c >> t1 >> t2){
        f.resize(n);
        dp.resize(n);
        for(int i = 0; i < n; i++)
            cin >> f[i];
        int ans = INF;
        for(int i = 0; i < n; i++){
            fill(all(dp), -1);
            s.clear();
            for(int j = 0; j < n; j++)
                s.push_back((f[j] - f[i] + c) % c);
            sort(all(s));
            ans = min(ans, solve(0));
        }
        cout << ans << "\n";
    }

    return 0;   
}
