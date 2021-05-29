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
    int t;
    cin >> t;
    while(t--){
        int a, b, c, n, A, B, C;
        cin >> a >> b >> c >> n;

        if((n + b + c - 2 * a) % 3){
            cout << "NO" << "\n";
            continue;
        }

        A = (n + b + c - 2 * a) / 3;
        B = A + a - b;
        C = n - A - B;

        cout << (A >= 0 && B >= 0 && C >= 0 ? "YES" : "NO") << "\n";    
    }
    
    return 0;   
}
