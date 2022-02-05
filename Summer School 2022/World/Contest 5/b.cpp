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
    
    string s, k, c;
    
    while(cin >> k){

        if(k == "0")
            break;

        cin >> s;

        c.assign(s.size(), '\0');

        for(int i = 0; i < s.size(); i++){
            
            int code = s[i] - 'A';
            int add = (k[i % k.size()] - 'A') + 1;
            
            c[i] = (char)((code + add) % 26 + 'A');
        }

        cout << c << "\n";
    }

    return 0;   
}
