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
        int n;
        int p = 0, c = 0;
        bool ans = true;

        cin >> n;

        while(n--){
            int pi, ci;
            cin >> pi >> ci;
            if(pi - p < 0 || ci - c < 0 || (pi - p) < (ci - c))
                ans = false;
            p = pi, c = ci;
        }

        cout << (ans ? "YES" : "NO") << "\n";
    }

    return 0;   
}
