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
        int n, U, R, D, L;
        bool ok = false;
        
        cin >> n >> U >> R >> D >> L;

        for(int i = 0; i < 2 && !ok; i++){
            for(int j = 0; j < 2 && !ok; j++){
                for(int k = 0; k < 2 && !ok; k++){
                    for(int m = 0; m < 2 && !ok; m++){
                        int u = U, r = R, l = L, d = D;

                        ok = true;

                        if(i){
                            u--; l--;
                        }
                        if(j){
                            u--; r--;
                        }
                        if(k){
                            d--; l--;
                        }
                        if(m){
                            d--; r--;
                        }

                        //cout << u << " " << r << " " << l << " " << d << " " << n - 2 << "\n";

                        if(u < 0 || u > n - 2){
                            ok = false;
                            //cout << "U\n";
                        }
                        if(r < 0 || r > n - 2){
                            ok = false;
                            //cout << "R\n";
                        }
                        if(l < 0 || l > n - 2){
                            ok = false;
                            //cout << "L\n";
                        }
                        if(d < 0 || d > n - 2){
                            ok = false;
                            //cout << "D\n";
                        }
                    }
                }
            }    
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
    
    return 0;   
}
