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
    vector<int> parent;
    UnionFind(int n){
        parent.resize(n);
        iota(all(parent), 0);
    }
    int find(int a){
        if(parent[a] == a) return a;
        parent[a] = find(parent[a]);
        return parent[a];
    }
    void merge(int a, int b){
        parent[find(a)] = find(b);
    }
};

int main(){
    optimize;
    
    int n, m;
    cin >> n >> m;

    UnionFind uf(n);
    vector<int> v(n, 0);

    while(m--){
        int k, a, b;
        cin >> k;
        if(k == 0) continue;
        cin >> a;
        for(int i = 1; i < k; i++){
            cin >> b;
            uf.merge(a - 1, b - 1);
        }
    }

    for(int i = 0; i < n; i++)
        v[uf.find(i)]++;
    for(int i = 0; i < n; i++)
        cout << v[uf.find(i)] << " ";
    cout << "\n";
    return 0;   
}
