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
    
    int cont = 0;
    
    string s, s2;
    cin >> s;

    for(int i = 0; i < s.size(); i++)
        if(s[i] == '4' || s[i] == '7')
            cont++;
    s2 = to_string(cont);
    
    bool ans = true;
    
    for(int i = 0; i < s2.size() && ans; i++){
        if(s2[i] != '4' && s2[i] != '7')
            ans = false;
    }

    cout << (ans ? "YES" : "NO") << "\n";

    return 0;   
}
