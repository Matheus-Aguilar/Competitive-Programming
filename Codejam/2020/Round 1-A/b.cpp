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

    int tests;
    cin >> tests;

    for(int t = 1; t <= tests; t++){
        int n;
        cin >> n;

        cout << "Case #" << t << ":\n";

        if(n < 30){
            for(int i = 1; i <= n; i++)
                cout << i << " " << 1 << "\n";
        }
        else{
            int m = n - 30;
            bool left = true;
            
            int r = 1;

            while(m){
                if(m & 1){
                    if(left){
                        for(int i = 1; i <= r; i++)
                            cout << r << " " << i << "\n";
                    }
                    else{
                        for(int i = r; i >= 1; i--)
                            cout << r << " " << i << "\n";
                    }
                    left = !left;
                    n -= (1 << r)/2;
                }
                else{
                    if(left)
                        cout << r << " " << 1 << "\n";
                    else
                        cout << r << " " << r << "\n";
                    n--;
                }

                r++;
                m >>= 1;
            }

            while(n){
                if(left)
                    cout << r << " " << 1 << "\n";
                else
                    cout << r << " " << r << "\n";
                r++;
                n--;
            }
        }
    }
    
    return 0;   
}
