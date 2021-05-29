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
 
unordered_map<string, vector<string>> g;
 
bool dfs(const string &a, const string &b){
    
    if(a == b)
        return true;
    
    vector<string> &adj = g[a];
 
    for(int i = 0; i < adj.size(); i++){
        if(dfs(adj[i], b))
            return true;
    }
 
    return false;
}
 
int main(){
    optimize;
    
    int n, m;
    cin >> n >> m;
 
    string a, b, aux;
 
    for(int i = 0; i < n; i++){
        
        cin >> a >> aux >> aux >> aux >> b;
        
        g[a].push_back(b);
    }
 
    for(int i = 0; i < m; i++){
        
        cin >> a >> aux >> aux >> aux >> b;
 
        if(dfs(a, b))
            cout << "Fact" << "\n";
        else if(dfs(b, a))
            cout << "Alternative Fact" << "\n";
        else
            cout << "Pants on Fire" << "\n";
    }
 
    return 0;   
}