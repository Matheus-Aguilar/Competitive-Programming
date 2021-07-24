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

pair<string, string> split(string &s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '@'){
            return make_pair(s.substr(0, i), s.substr(i + 1, s.size() - i - 1));
        }
    }
}

void clean(string &s){
    string aux = "";

    for(int i = 0; i < s.size() && s[i] != '+'; i++){
        if(s[i] != '.')
            aux.push_back(s[i]);
    }

    s = aux;
}

int main(){
    optimize;

    int n;
    cin >> n;

    vector<pair<string, string>> addr(n);

    string s;

    for(int i = 0; i < n; i++){
        cin >> s;
        
        addr[i] = split(s);

        clean(addr[i].first);
    }

    sort(all(addr));
    addr.resize(unique(all(addr)) - addr.begin());

    cout << addr.size() << "\n";

    return 0;   
}
