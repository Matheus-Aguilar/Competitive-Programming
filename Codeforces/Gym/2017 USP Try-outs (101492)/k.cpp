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

    ll fa[40], ua[40], fb[40], ub[40];
    
    fa[0] = 1;
    ua[0] = 0;
    fb[0] = 0;
    ub[0] = 0;

    for(int i = 1; i <= 30; i++){
        fa[i] = fa[i - 1];
        fb[i] = fb[i - 1];
        ua[i] = ua[i - 1] + 2 * fb[i - 1] + ub[i - 1];
        ub[i] = ub[i - 1] + 2 * fa[i - 1] + ua[i - 1];
    }
    
    int k;
    cin >> k;

    cout << fa[k] + fb[k] + ua[k] + ub[k] << "\n";

    return 0;   
}
