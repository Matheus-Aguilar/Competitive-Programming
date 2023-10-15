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

    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    bool prefix = (s.size() <= t.size() && s == t.substr(0, s.size()));
    bool suffix = (s.size() <= t.size() && s == t.substr(t.size() - s.size(), s.size()));

    if(prefix && suffix)
        cout << 0 << "\n";
    else if(prefix)
        cout << 1 << "\n";
    else if(suffix)
        cout << 2 << "\n";
    else
        cout << 3 << "\n";
    
    return 0;   
}
