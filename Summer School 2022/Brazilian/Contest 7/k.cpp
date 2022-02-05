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

bool solve(string &s){
    stringstream ss;
    ss << s;

    ll a, b, c;
    char op, eq;

    ss >> a >> op >> b >> eq >> c;

    string aux = to_string(a) + op + to_string(b) + eq + to_string(c);

    if(aux.size() != s.size())
        return false;

    if(op == '+')
        return a + b == c;
    if(op == '-')
        return a - b == c;
    return a * b == c;
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        string s0;
        cin >> s0;

        int ans = -1;

        vector<bool> v(10, false);

        for(int i = 0; i < s0.size(); i++){
            if(s0[i] >= '0' && s0[i] <= '9')
                v[s0[i] - '0'] = true;
        }

        for(int i = 0; i < 10 && ans == -1; i++){

            if(v[i]) continue;

            string s = s0;
            
            for(int j = 0; j < s.size(); j++){
                if(s[j] == '?')
                    s[j] = ('0' + i);
            }

            if(solve(s))
                ans = i;
        }

        cout << ans << "\n";
    }
    
    return 0;   
}
