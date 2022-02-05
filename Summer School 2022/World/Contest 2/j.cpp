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
    
    int m;

    while(cin >> m && m) {
        string s;
        
        vector<int> f(256, 0);

        cin.ignore();
        getline(cin, s);

        int ans = 0, n = s.size(), cont = 0, l = 0, r = -1;

        while(l < n){
            if(r + 1 < n && cont <= m){
                r++;
                f[s[r]]++;
                if(f[s[r]] == 1)
                    cont++;
            }
            else {
                f[s[l]]--;
                if(f[s[l]] == 0)
                    cont--;
                l++;
            }

            if(cont <= m){
                ans = max(ans, r - l + 1);
            }
        }

        cout << ans << "\n";
    }

    return 0;   
}
