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
#define MAXN 75

using namespace std;

ll fibo[MAXN];

void precalc(){
    
    fibo[0] = fibo[1] = 1;

    for(int i = 2; i < MAXN; i++){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}

int main(){
    optimize;

    precalc();

    ll n, m, p = 0;
    cin >> n;

    if(n == 1){
        cout << "B" << "\n";
        return 0;
    }

    m = n;

    int pos = -1;

    while(m % 2 == 0){

        pos = lower_bound(fibo, fibo + MAXN, m) - fibo;

        if(fibo[pos] == m){
            break;
        }

        m /= 2;
        p++;
    }

    pos = lower_bound(fibo, fibo + MAXN, m) - fibo;

    if(fibo[pos] != m){
        cout << "IMPOSSIBLE" << "\n";
    } else {
        
        string ans = "";

        for(int i = 0; i < pos - 1; i++){
            ans += 'A';
        }

        ans += 'B';

        for(int i = 0; i < p; i++){
            ans += "AB";
        }

        cout << ans << "\n";
    }

    return 0;   
}
