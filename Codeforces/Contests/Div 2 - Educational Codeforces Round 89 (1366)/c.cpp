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
#define MAXN 50

using namespace std;

int n, m;
int mat[MAXN][MAXN];

struct UnionFind{
    vector<int> par;
    vector<int> sz;
    vector<pii> ct;
    UnionFind(int n){
        par.resize(n);
        sz.resize(n);
        ct.resize(n);

        for(int i = 0; i < n; i++){
            par[i] = i;
            sz[i] = 1;
            ct[i].first = (mat[i / m][i % m] == 0);
            ct[i].second = (mat[i / m][i % m] == 1); 
        }
    }
    int find(int a){
        if(par[a] != a)
            par[a] = find(par[a]);
        return par[a];
    }
    void merge(pii a, pii b){
        int parA = find(m * a.first + a.second);
        int parB = find(m * b.first + b.second);
        if(parA == parB)
            return;
        if(sz[parA] > sz[parB])
            swap(parA, parB);
        par[parA] = parB;
        sz[parB] += sz[parA];
        ct[parB].first += ct[parA].first;
        ct[parB].second += ct[parA].second; 
        ct[parA].first = ct[parA].second = 0;
    }
    int getMin(){
        int sum = 0;
        for(int i = 0; i < ct.size(); i++)
            sum += min(ct[i].first, ct[i].second);
        return sum;
    }
};

int main(){
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        
        cin >> n >> m;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> mat[i][j];

        UnionFind uf(n * m);
        vector<vector<pii>> dist(n + m);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dist[i + j].push_back(pii(i, j));
            }
        }

        for(int i = 0; i < n + m; i++){
            for(int j = 0; j < dist[i].size(); j++){
                for(int k = 0; k < dist[n + m - i - 2].size(); k++){
                    if(dist[i][j].first <= dist[n + m - i - 2][k].first && dist[i][j].second <= dist[n + m - i - 2][k].second){
                        uf.merge(dist[i][j], dist[n + m - i - 2][k]);
                    }
                }   
            }
        }

        cout << uf.getMin() << "\n";
    }

    return 0;   
}
