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

ll fastExpo(ll x, int y){
    ll r = 1;
    while(y > 0){
        if(y & 1)
            r *= x;
        x *= x;
        y >>= 1;
    }
    return r;
}

int main(){
    optimize;
    
    int n, s;
    bool ok = false;

    ll m, sum;

    cin >> m;

    for(int i = 3; i < 60 && !ok; i++){
        
        s = 1;
        sum = 0;

        while(sum < m){
            sum += fastExpo(s, i - 1);
            s++;
        }

        if(sum == m){
            n = i;
            s--;
            ok = true;
        }
    }

    if(!ok)
        cout << "impossible" << "\n";
    else
        cout << n << " " << s << "\n";

    return 0;   
}
