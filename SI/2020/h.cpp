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
    
    ll a, b;
    cin >> a >> b;

    int p[3] = {2, 3, 5};
    int cont1[3] = {0, 0, 0};
    int cont2[3] = {0, 0, 0};

    for(int i = 0; i < 3; i++){
        while(a % p[i] == 0){
            a /= p[i];
            cont1[i]++;
        }
        while(b % p[i] == 0){
            b /= p[i];
            cont2[i]++;
        }
    }

    if(a != b)
        cout << -1 << "\n";
    else
        cout << abs(cont1[0] - cont2[0]) + abs(cont1[1] - cont2[1]) + abs(cont1[2] - cont2[2]) << "\n"; 

    return 0;   
}
