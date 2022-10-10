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

int cont[11][11];

int main(){
    optimize;

    int n;
    cin >> n;

    while(n--){
        int d, l, r, c;
        cin >> d >> l >> r >> c;

        if(d == 0){
            for(int i = c; i <= c + l - 1; i++){
                if(i > 10){
                    cout << "N" << "\n";
                    return 0;
                }
                else{
                    cont[r][i]++;
                    if(cont[r][i] > 1){
                        cout << "N" << "\n";
                        return 0;
                    }
                }
            }
        }
        else{
            for(int i = r; i <= r + l - 1; i++){
                if(i > 10){
                    cout << "N" << "\n";
                    return 0;
                }
                else{
                    cont[i][c]++;
                    if(cont[i][c] > 1){
                        cout << "N" << "\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Y" << "\n";
    
    return 0;   
}
