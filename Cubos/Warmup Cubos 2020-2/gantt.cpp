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


int main() {
    
    optimize;
    
    int bal = 0;
    string s;
    
    cin >> s;
    
    for(int i = 0; i < (int)s.size() && bal >= 0; i++)
        bal += (s[i] == '(' ? 1 : -1);
    
    cout << (bal == 0 ? "VALIDO" : "INVALIDO") << "\n";
    
    return 0;
}
