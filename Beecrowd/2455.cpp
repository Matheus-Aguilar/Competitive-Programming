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

    int p1, p2, c1, c2;
    cin >> p1 >> c1 >> p2 >> c2;
    if(p1 * c1 > p2 * c2)
        cout << -1 << "\n";
    else if(p1 * c1 < p2 * c2)
        cout << 1 << "\n";
    else
        cout << 0 << "\n";

    return 0;   
}
