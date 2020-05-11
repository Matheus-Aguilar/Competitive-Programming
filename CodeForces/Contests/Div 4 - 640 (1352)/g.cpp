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
        int n;
        cin >> n;
        if(n <= 3){
            cout << -1 << "\n";
        }
        else{

            int i, cont = 0;

            if(n % 2){
                for(i = 1; i <= n; i += 2){
                    cout << i << " ";
                    cont++;
                }
            }
            else{
                for(i = 2; i <= n; i += 2){
                    cout << i << " ";
                    cont++;
                }
            }

            i -= 5;
            cout << i << " ";
            cont++;
        
            i += 2;
            cout << i << " ";
            cont++;

            if(cont < n){
                i -= 4;
                cout << i << " ";
                cont++;
                while(cont < n){
                    i -= 2;
                    cout << i << " ";
                    cont++;
                }
            }
            cout << "\n";
        }
    }

    return 0;   
}
