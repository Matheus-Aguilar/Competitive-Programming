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

struct cmp{
    bool operator()(const string &a, const string &b){
        if(a.size() != b.size())
            return a.size() < b.size();
        return a < b;
    }
};

int main(){
    optimize;
    
    int n, m, cont = 0, ans = 0;
    cin >> n >> m;

    set<string, cmp> st;
    while(m--){
        string s;
        cin >> s;
        st.insert(s);
    }

    for(auto it:st){
        cont += it.size() + 1;
        if(cont > n + 1) break;
        ans++;
    }

    cout << ans << "\n";

    return 0;   
}
