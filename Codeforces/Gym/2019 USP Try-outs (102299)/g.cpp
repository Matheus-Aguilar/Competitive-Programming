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

struct UnionFind{
    vector<int> par, mini;

    UnionFind(int n, vector<int> &p){
        par.resize(n);
        mini.resize(n);

        for(int i = 0; i < n; i++){
            par[i] = i;
            mini[i] = p[i];
        }
    }

    //B -> A
    void merge(int a, int b){
        pair<int, int> parA = find(a), parB = find(b);

        par[parB.first] = par[parA.first];
        mini[parB.first] = min(mini[parB.first], parA.second);
    }

    pair<int, int> find(int a){
        
        if(a == par[a])
            return make_pair(a, mini[a]);

        pair<int, int> parA = find(par[a]);
        
        par[a] = parA.first;
        mini[a] = min(mini[a], parA.second);

        return make_pair(par[a], mini[a]);
    }

    int getMin(int a){
        return find(a).second;
    }
};

int main(){
    optimize;

    int n, m;
    cin >> n >> m;
    
    vector<int> p(n);

    for(int i = 0; i < n; i++)
        cin >> p[i];

    UnionFind uf(n, p);

    while(m--){
        char op;
        cin >> op;

        if(op == '?'){
            int a;
            cin >> a;
            cout << uf.getMin(a - 1) << "\n";
        }
        else{
            int a, b;
            cin >> a >> b;
            uf.merge(a - 1, b - 1);
        }
    }

    return 0;   
}
