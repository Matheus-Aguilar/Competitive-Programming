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

int n, c, m = 0;
vector<string> str;
string t = "";

void solve(int i, vector<string> s, string &cur){

    if(s.size() == 0 || s.size() < m)
        return;
    
    if(i == c){
        if(s.size() > m || (s.size() == m && cur < t)){
            t = cur;
            m = s.size();
        }
    }

    for(char ch = 'a'; ch <= 'z'; ch++){
        
        vector<string> s2;
        
        for(int j = 0; j < s.size(); j++){
            if(s[j][i] == '*' || s[j][i] == ch){
                s2.push_back(s[j]);
            }
        }

        cur += ch;
        solve(i + 1, s2, cur);
        cur.pop_back();
    }
}

int main(){
    optimize;

    cin >> n >> c;

    str.resize(n);

    for(int i = 0; i < n; i++)
        cin >> str[i];
    
    string cur = "";

    solve(0, str, cur);

    cout << t << " " << m << endl;

    return 0;   
}
