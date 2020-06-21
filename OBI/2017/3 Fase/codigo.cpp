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

    int n;
    cin >> n;

    unordered_map<string, bool> prefix;
    unordered_map<string, bool> suffix;

    bool ans = true;

    for(int i = 0; i < n && ans; i++){
        string s;
        cin >> s;

        ans = (prefix.find(s) == prefix.end());

        for(int j = 1; j < (int)s.size() && ans; j++)
            if(prefix.find(s.substr(0, j)) != prefix.end() && suffix.find(s.substr(j, (int)s.size() - j)) != suffix.end())
                ans = false;
        for(int j = 0; j < s.size() && ans; j++)
            prefix[s.substr(j, (int)s.size() - j)] = true;
        for(int j = 1; j <= (int)s.size() && ans; j++)
            suffix[s.substr(0, j)] = true;            
        if(!ans)
            cout << s << "\n";
    }

    if(ans)
        cout << "ok" << "\n";
    
    return 0;   
}
