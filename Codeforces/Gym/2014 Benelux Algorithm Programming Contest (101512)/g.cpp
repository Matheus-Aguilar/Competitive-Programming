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

    int T;
    cin >> T;

    while(T--){
        int n, best, t = -INF;
        cin >> n;

        for(int i = 1; i <= n; i++){
            
            int a, b, c, delta;
            cin >> a >> b >> c;
            
            delta = b * b + 4 * a * c;

            if(t < delta / (4 * a)){
                t = delta / (4 * a);
                best = i;
            }
        }

        cout << best << "\n";
    }
    
    return 0;   
}
