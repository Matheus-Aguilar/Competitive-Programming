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

int n, cont = 0, cur = 0;

vector<vector<int>> adj;
vector<int> p;
vector<int> pos;
vector<bool> v;

void add(int x){
    cont++;
    adj[x].push_back(cont);
    p[cont] = x;
}

void die(int x){
    v[x] = false;
}

bool update(int u){
    if(v[u]){
        cur = u;
        return true; 
    }

    for(int i = pos[u]; i < adj[u].size(); i++){
        
        pos[u]++;
        
        if(update(adj[u][i])){
            return true;            
        }
    }

    if(update(p[u])){
        return true;
    }

    return false;
}

int main(){
    optimize;
    
    cin >> n;

    adj.resize(n);
    p.resize(n);
    pos.assign(n, 0);
    v.assign(n, true);

    for(int i = 0; i < n; i++){
        int x, t;
        cin >> t >> x;

        if(t == 1){
            add(x - 1);
        }
        else{
            die(x - 1);
            update(cur);
            cout << cur + 1 << "\n";
        }
    }

    return 0;   
}
