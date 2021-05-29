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
    
    ll a, b, c, da, db, dc;
    char dec;
    cin >> a >> dec >> da >> b >> dec >> db >> c >> dec >> dc;

    a = 100 * a + da;
    b = 100 * b + db;
    c = 100 * c + dc;

    cout << (100 * (a * b + a * c + b * c) / (a * b * c) < 1LL ? "Yes" : "No") << "\n";
    
    return 0;   
}
