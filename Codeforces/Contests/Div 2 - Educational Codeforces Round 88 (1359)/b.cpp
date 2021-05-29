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
        ll n, m, x, y;
        cin >> n >> m >> x >> y;

        vector<string> s(n);
        for(int i = 0; i < n; i++)
            cin >> s[i];
        
        ll ans = 0;
        
        if(2 * x <= y){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(s[i][j] == '.')
                        ans += x;
                }
            }
        }
        else{
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    if(s[i][j] == '.'){
                        if(j < m - 1 && s[i][j + 1] == '.'){
                            ans += y;
                            j++;
                        }
                        else
                            ans += x;
                    }
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;   
}
