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
    
    ll N, M, ax, ay, bx, by;
    long double R, ans;

    cin >> M >> N >> R;
    cin >> ax >> ay >> bx >> by;

    if(by > ay){
        swap(ax, bx);
        swap(ay, by);
    }

    ans = INF;

    for(int i = 0; i <= by; i++){
        ans = min(ans, 2 * (R / N) * i + (abs(ax - bx) * PI * R * (by - i)) / (M * N));
    }

    ans += abs(ay - by) * R / N;

    cout << fixed << setprecision(12) << ans << "\n";

    return 0;   
}
