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

ll d[20];

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){

        int sz = 0;
        ll n;

        cin >> n;

        while(n > 0){
            d[sz++] = n % 10;
            n /= 10;
        }

        int best = INF;

        for(int i = 0; i < sz; i++){
            for(int j = i + 1; j < sz; j++){
                if((10 * d[j] + d[i]) % 25 == 0){
                    best = min(best, i + (j - i - 1));
                }
            }
        }

        cout << best << "\n";
    }
    
    return 0;   
}
