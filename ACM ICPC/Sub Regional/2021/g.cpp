#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll unsigned long long
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
    
    fibo[0] = fibo[1] = 1LL;

    for(int i = 2; i < MAXN; i++){
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
}

int main(){
    optimize;

    precalc();

    ll n;
    cin >> n;

    if(n == 1) {
        cout << "B" << "\n";
        return 0;
    }

    string ans = "";

    for(int i = MAXN - 1; i > 1; i--){
        while(n % fibo[i] == 0LL){
            
            for(int j = 0; j < i - 1; j++){
                ans += 'A';
            }
            
            ans += 'B';
            n /= fibo[i];
        }
    }

    if(n == 1LL){
        cout << ans << "\n";
    }
    else {
        cout << "IMPOSSIBLE" << "\n";
    }

    return 0;   
}