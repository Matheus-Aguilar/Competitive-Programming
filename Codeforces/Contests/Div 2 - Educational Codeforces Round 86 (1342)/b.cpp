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

string solve(int n){
    string s = "";
    while(n--) s += "10";
    return s;
}

int main(){
    optimize;

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;

        if(count(all(s), '0') == 0 || count(all(s), '1') == 0)
            cout << s << "\n";
        else
            cout << solve(s.size()) << "\n";
    }
    
    return 0;   
}
