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

int m(char c){
    return (int)(c - 'a');
}

int main(){
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        
        if(s.size() == 1){
            cout << "YES" << "\n";
            cout << "abcdefghijklmnopqrstuvwxyz" << "\n";
            continue;
        }

        vector<unordered_set<char>> adj(26);
        for(int i = 1; i < s.size(); i++){
            int u = m(s[i - 1]);
            int v = m(s[i]);
            adj[u].insert(v);
            adj[v].insert(u);
        }

        bool ans = true;
        int key = -1;
        string keyboard = "";

        for(int i = 0; i < 26 && ans; i++){
            if(adj[i].size() > 2) ans = false;
            else if(adj[i].size() == 1) key = i;
            else if(adj[i].size() == 0) keyboard += (char)('a' + i);
        }
        
        if(!ans || key == -1){
            cout << "NO" << "\n";
        }
        else{
            cout << "YES" << "\n";
            while(adj[key].size() > 0){
                keyboard += (char)('a' + key);
                key = *adj[key].begin();
                adj[key].erase(m(keyboard.back()));
            }
            keyboard += (char)('a' + key);
            cout << keyboard << "\n";
        }
    }

    return 0;   
}
