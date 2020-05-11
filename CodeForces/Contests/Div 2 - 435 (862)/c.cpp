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
    
    int n, x, xr = 0;
    cin >> n >> x;
    
    if(x & 1){
        cout << "YES" << "\n";
        for(int i = 0; i < n - 1; i++){
            cout << 2 * i << " ";
            xr ^= 2 * i;
        }
        cout << (xr ^ x) << "\n";
    }
    else{
        if(n & 1){
            cout << "YES" << "\n";
            for(int i = 0; i < n - 1; i++){
                cout << 2 * i + 1 << " ";
                xr ^= 2 * i + 1;
            }
            cout << (xr ^ x) << "\n";
        }
        else{
            if(n == 2){
                if(x == 0)
                    cout << "NO" << "\n";
                else{
                    cout << "YES" << "\n" << 0 << " " << x << "\n";
                }
                return 0;
            }


            int max2 = (2 << (int)(log2(2 * n + 1)));
            int max4 = 2 * max2;

            cout << "YES" << "\n";
            
            for(int i = 0; i < n - 1; i++){
                if(i == 0){
                    cout << 2 * i + 1 + max2 + max4 << " ";
                    xr ^= 2 * i + 1 + max2 + max4;
                }
                else if(i == 1){
                    cout << 2 * i + 1 + max2 << " ";
                    xr ^= 2 * i + 1 + max2;
                }
                else{
                    cout << 2 * i + 1 + max4 << " ";
                    xr ^= 2 * i + 1 + max4;
                }
            }
            cout << (xr ^ x) << "\n";
        }
    }

    return 0;   
}
