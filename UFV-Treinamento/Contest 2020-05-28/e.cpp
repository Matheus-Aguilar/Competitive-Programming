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
    
    ll n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<bool> A(n + 1, false);
    vector<bool> B(n + 1, false);
    vector<bool> C(n + 1, false);

    for(int i = 0; i <= n; i += a)
        A[i] = true;
    for(int i = 0; i <= n; i += b)
        B[i] = true;
    for(int i = 0; i <= n; i += c)
        C[i] = true;

    ll ans = 0;

    for(int i = n; i >= 0; i--){
        if(A[i]){
            for(int j = n - i; j >= 0; j--){
                if(B[j] && C[n - i - j]){
                    ans = max(ans, i/a + j/b + (n - i - j)/c); 
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;   
}
