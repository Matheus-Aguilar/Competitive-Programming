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

int a[10001];

int main(){
    optimize;

    ms(a, -1);

    ll n;
    while(cin >> n){
        if(a[n] == -1){
            ll rem = 1, pot = 1, cont = 1;
            while(rem != 0){
                pot = ((pot % n) * (10 % n)) % n;
                rem = (rem + pot) % n;
                cont++;
            }
            a[n] = cont;
        }
        cout << a[n] << "\n";
    }

    return 0;   
}
