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

int cont[100][2];

int main(){
    optimize;
    
    int n, ans = 0;
    cin >> n;

    while(n--){
        int m, par;
        char l;

        cin >> m >> l;

        cont[m][(l - 'D')]++;
        
        par = min(cont[m][0], cont[m][1]);
        ans += par;
        cont[m][0] -= par;
        cont[m][1] -= par;
    }

    cout << ans << "\n";

    return 0;   
}
