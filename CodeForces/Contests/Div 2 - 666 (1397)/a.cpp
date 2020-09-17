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
        cin >> n;

        vector<int> f(26, 0);

        string s;

        for(int i = 0; i < n; i++){
            cin >> s;
            for(int j = 0; j < s.size(); j++)
                f[(int)(s[j] - 'a')]++;
        }

        bool ans = true;

        for(int i = 0; i < 26 && ans; i++)
            ans = (f[i] % n == 0);
    
        cout << (ans ? "YES" : "NO") << "\n";
    }
    
    return 0;   
}
