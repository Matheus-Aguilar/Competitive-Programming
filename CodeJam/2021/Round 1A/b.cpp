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

ll bt(int i, int n, ll sum, ll prod, vector<int> &v){
    if(i == n)
        return (sum == prod ? sum : 0);
    return max(bt(i + 1, n, sum + v[i], prod, v), bt(i + 1, n, sum, prod * v[i], v));
}

int main(){
    optimize;

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){

        int m;
        cin >> m;

        vector<int> p(m), n(m), v;

        for(int i = 0; i < m; i++){
            
            cin >> p[i] >> n[i];

            for(int j = 0; j < n[i]; j++){
                v.push_back(p[i]);
            }
        }

        ll ans = bt(0, v.size(), 0, 1, v);

        cout << "Case #" << t << ": " << ans << "\n";
    }
    
    return 0;   
}
