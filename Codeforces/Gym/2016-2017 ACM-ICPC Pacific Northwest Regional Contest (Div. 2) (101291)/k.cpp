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

    int a[6], b[6], win = 0, cont = 0;

    for(int i = 0; i < 6; i++)
        cin >> a[i];
    
    for(int i = 0; i < 6; i++)
        cin >> b[i];
    
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            win += (a[i] > b[j]);
            cont += (a[i] != b[j]);
        }        
    }

    if(cont == 0) cont = 1;

    cout << fixed << setprecision(5) << (1.0 * win) / cont << "\n";

    return 0;   
}
