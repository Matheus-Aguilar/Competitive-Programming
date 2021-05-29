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
        int n, k, half;
        cin >> n >> k;

        string s, sk = "";
        cin >> s;

        half = n/(2 * k);

        vector<vector<int>> f(n, vector<int>(26, 0));
        for(int i = 0; i < n; i++){
            int pos = i % k;
            if(pos >= k/2) pos = k - pos - 1;
            int l = (int)(s[i] - 'a');
            f[pos][l]++;
        }

        int teto = (int)(ceil(k/2.0));

        for(int i = 0; i < teto; i++){
            sk += (char)('a' + (max_element(all(f[i])) - f[i].begin()));
        }

        ll ans = 0;

        for(int i = 0; i < n; i ++){
            int pos = i % k;
            if(pos >= k/2) pos = k - pos - 1;
            if(s[i] != sk[pos])
                ans++;
        }

        cout << ans << "\n";
    }
    
    return 0;   
}
