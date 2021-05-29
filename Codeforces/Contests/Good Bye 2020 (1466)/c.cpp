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

bool check(string &s, int i){
    if(i - 1 >= 0 && s[i - 1] == s[i]) return false;
    if(i - 2 >= 0 && s[i - 2] == s[i]) return false;
    if(i + 1 < s.size() && s[i + 1] == s[i]) return false;
    if(i + 2 < s.size() && s[i + 2] == s[i]) return false;
    return true;
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){

        int ans = 0;

        string s;
        cin >> s;

        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i - 1] || (i > 1 && s[i] == s[i - 2])){
                for(char c = 'a'; c <= 'z' && !check(s, i); c++)
                    s[i] = c;   
                ans++;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;   
}
