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
    
    int n, t, m;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        m = min(m, x);
        if(i == 2) t = x;
    }

    cout << 2 + (t ^ m) << "\n";

    return 0;   
}
