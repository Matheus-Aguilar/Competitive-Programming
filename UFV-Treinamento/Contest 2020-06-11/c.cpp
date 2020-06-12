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
    
    ll n, m, cont = 0;
    cin >> n >> m;

    if(m % n != 0)
        cout << -1 << "\n";
    else{
        m /= n;
        while(m % 2 == 0){
            m /= 2;
            cont++;
        }
        while(m % 3 == 0){
            m /= 3;
            cont++;
        }

        cout << (m == 1 ? cont : -1) << "\n";
    }

    return 0;   
}
