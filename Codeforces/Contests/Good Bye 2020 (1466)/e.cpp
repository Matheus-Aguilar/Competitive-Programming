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
#define MAXN 500010

using namespace std;

ll p[60], x[MAXN], c[MAXN];

void precalc(){
    p[0] = 1;

    for(int i = 1; i < 60; i++)
        p[i] = (2 * p[i - 1]) mod;
}

int main(){
    optimize;

    precalc();

    int t;
    cin >> t;

    while(t--){
        
        int n;
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> x[i];

        for(int i = 0; i < 60; i++){

            c[i] = 0;

            for(int j = 0; j < n; j++){
                if(x[j] & (1LL << i))
                    c[i]++;
            }
        }

        ll sum = 0;

        for(int i = 0; i < n; i++){
            
            ll a = 0, b = 0;
            
            for(int j = 0; j < 60; j++){
                if(x[i] & (1LL << j)){
                    a = (a + (c[j] * p[j]) mod) mod;
                    b = (b + (n * p[j]) mod) mod; 
                }
                else{
                    b = (b + (c[j] * p[j]) mod) mod;
                }
            }

            sum = (sum + (a * b) mod) mod;
        }

        cout << sum << '\n';
    }
    
    return 0;   
}
