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

int solve_prefix(string &s, vector<string> &v){
    if(s[0] == '*') return 0;
    int i = 0;
    while(s[i] != '*') i++;
    v.push_back(s.substr(0, i));
    return i;
}

int solve_suffix(string &s, vector<string> &v){
    if(s.back() == '*') return s.size() - 1;
    int i = s.size() - 1;
    while(s[i] != '*') i--;
    v.push_back(s.substr(i + 1, s.size() - i - 1));
    return i;
}

void solve_middle(string &s, int l, int r, string &m){
    for(int i = l + 1; i < r; i++)
        if(s[i] != '*')
            m += s[i];
}

int main(){
    optimize;
    
    int tests;
    cin >> tests;
    for(int t = 1; t <= tests; t++){
        int n;
        cin >> n;

        string s;
        vector<string> prefix;
        vector<string> suffix;
        string middle = "";

        while(n--){
            int l, r;
            cin >> s;
            l = solve_prefix(s, prefix);
            r = solve_suffix(s, suffix);
            solve_middle(s, l, r, middle);
        }

        sort(all(prefix), [](const string &a, const string &b){return a.size() > b.size();});
        sort(all(suffix), [](const string &a, const string &b){return a.size() > b.size();});

        bool ans = true;

        for(int i = 1; i < prefix.size(); i++){

            int size = prefix[i].size();

            if(prefix[0].substr(0, size) != prefix[i]){
                ans = false;
                break;
            }
        }

        for(int i = 1; i < suffix.size(); i++){

            int pos = suffix[0].size() - suffix[i].size();
            int size = suffix[i].size();

            if(suffix[0].substr(pos, size) != suffix[i]){
                ans = false;
                break;
            }
        }

        prefix.push_back("");
        suffix.push_back("");

        cout << "Case #" << t << ": ";

        if(ans){
            cout << prefix[0] << middle << suffix[0] << "\n";
        }
        else{
            cout << "*" << "\n";
        }
    }

    return 0;   
}
