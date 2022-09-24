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

    for(int t = 1; t <= T; t++){
        int n, k;
        cin >> n >> k;

        vector<int> s(n);

        for(int i = 0; i < n; i++)
            cin >> s[i];

        bool ok = true;
        vector<int> c(101, 0);
    
        if(n > 2 * k)
            ok = false;
        
        for(int i = 0; i < n && ok; i++){
            if(++c[s[i]] > 2)
                ok = false;
        }

        cout << "Case #" << t << ": " << (ok ? "YES" : "NO") << "\n";
    }

    return 0;   
}
