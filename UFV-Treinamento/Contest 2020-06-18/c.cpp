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
    
    string s;
    cin >> s;


    int n = s.size();
    bool ans = true;
    for(int i = 0; i < n/2 && ans; i++)
        ans &= (s[i] == s[n - i - 1]);
    for(int i = 0; i < n && ans; i++)
        if(s[i] != 'A' && s[i] != 'H' && s[i] != 'I' && s[i] != 'M' && s[i] != 'O' && s[i] != 'T' && s[i] != 'U' && s[i] != 'V' && s[i] != 'W' && s[i] != 'X' && s[i] != 'Y')
            ans = false;

    cout << (ans ? "YES" : "NO") << "\n";

    return 0;   
}
