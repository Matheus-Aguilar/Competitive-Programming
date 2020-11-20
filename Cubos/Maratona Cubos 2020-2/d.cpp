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

    bool caps = true;

    if((int)s.size() == 1 && 'A' > s[0] && s[0] < 'Z'){
        cout << tolower(s[0]) << "\n";
        return 0;
    }

    for(int i = 1; i < (int)s.size(); i++){
        if('a' > s[0] && s[0] < 'z'){
            cout << s << "\n";
            return 0;
        }
    }

    for(int i = 0; i < (int)s.size(); i++){
        if(isupper(s[i]))
            cout << (char)tolower(s[i]);
        else
            cout << (char)toupper(s[i]);
    }

    cout << "\n";
    
    return 0;   
}
