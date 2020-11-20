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
#define MAXN 100001
#define MAXM 20

using namespace std;

int main(){
    optimize;
    
    int t;
    cin >> t;

    int g[MAXN];
    bool st[MAXM];

    ms(g, -1);

    g[1] = 0;
    for(int i = 2; i < MAXN; i++){
        
        ms(st, false);
        st[0] = true;
        
        int r = sqrt(i);

        for(int j = 2; j <= r; j++){
            if(i % j == 0){
                st[g[j]] = true;
                st[g[i/j]] = true;
            }
        }

        for(int j = 1; j < MAXM; j++){
            if(!st[j]){
                g[i] = j;
                break;
            }
        }
    }

    while(t--){
        ll a, b, bira = 0, gui = 0;
        cin >> a >> b;

        int sz = b - a + 1;
        
        cout << (1LL << sz) << "\n";
        return 0;

        for(ll i = 1; i <= (1LL << sz) - 1; i++){
            int xr = 0;
            for(ll j = a, k = 0; j <= b; j++, k++){
                if(i & (1LL << k)){
                    xr ^= g[j];
                }
            }
            if(xr)
                bira = (bira + 1) mod;
            else
                gui = (gui + 1) mod;
        }
        cout << bira << " " << gui << "\n";
    }

    return 0;   
}