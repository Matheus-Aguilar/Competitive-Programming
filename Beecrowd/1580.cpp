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
#define MAXN 1001

using namespace std;

const ll p = 1000000007;
ll fat[MAXN];
ll cont[26];

void preCalc(){
    fat[0] = 1LL;
    for(int i = 1; i < MAXN; i++)
        fat[i] = (i * fat[i - 1]) mod;
}

ll fastExpo(ll x, ll y){
    ll r = 1LL;
    while(y > 0){
        if(y & 1)
            r = (r * x) mod;
        x = (x * x) mod;
        y >>= 1;
    }
    return r;
}

int main(){
    optimize;

    preCalc();

    string s;
    while(cin >> s){
        
        ll num = 1LL;
        ll den = 1LL;

        ms(cont, 0);
        for(int i = 0; i < s.size(); i++)
            cont[(int)(s[i] - 'A')]++;

        num = fat[s.size()];
        for(int i = 0; i < 26; i++)
            den = (den * fat[cont[i]]) mod;

        cout << (num * fastExpo(den, p - 2)) mod << "\n";
    }
    
    return 0;   
}
