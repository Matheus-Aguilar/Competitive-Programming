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
#define MAXN 800100

using namespace std;

vector<int> g[2 * MAXN]; //Implication graph
vector<int> gr[2 * MAXN]; //Reverse implication graph

bool visit[2 * MAXN]; //Vertices visited by dfs
int order[2 * MAXN]; //Graph traversal order
int pos = 0; //Position in the order array

int cont = 0; //Number of Strongely Connected Components
int comp[2 * MAXN]; //Strongely Connected Component of the Vertex
bool val[MAXN]; //Value of the variable

void dfs1(int u){
    visit[u] = true;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(!visit[v])
            dfs1(v);
    }
    order[pos++] = u;
}

void dfs2(int u){
    comp[u] = cont;
    for(int i = 0; i < gr[u].size(); i++){
        int v = gr[u][i];
        if(!comp[v])
            dfs2(v);
    }
}

void kosaraju(int n){
    for(int i = 0; i < n; i++){
        if(!visit[i]){
            dfs1(i);
        }
    }
    for(int i = 0; i < n; i++){
        int u = order[n - i - 1];
        if(!comp[u]){
            cont++;
            dfs2(u);
        }
    }
}

bool solve2SAT(int n){
    kosaraju(2 * n);
    for(int i = 0; i < n; i++){
        if(comp[2 * i] == comp[2 * i + 1])
            return false;
        val[i] = (comp[2 * i] > comp[2 * i + 1]);
    }
    return true;
}

//notP = false if p is in the clause
//notP = true if ~p is in the clause
void addClause(int p, bool notP, int q, bool notQ){
    //p ^ q <=> ~p -> q <=> ~q -> p
    //Adjust vertex labels to deal with a 2N size graph
    p = 2 * p + notP;
    q = 2 * q + notQ;

    //Add implication graph edges
    g[p ^ 1].push_back(q); // ~p -> q
    g[q ^ 1].push_back(p); // ~q -> p
    
    //Add reverse implication graph edges
    gr[q].push_back(p ^ 1); // q -> ~p
    gr[p].push_back(q ^ 1); // p -> ~q
}

int main(){
    optimize;

    int n, p, M, m;
    cin >> n >> p >> M >> m;

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        addClause(x - 1, 0, y - 1, 0); //(x ^ y)
    }

    for(int i = 0; i < p; i++){
        int l, r;
        cin >> l >> r;
        if(l > 1) 
            addClause(i, 1, p + l - 2, 1); //i -> f > l <=> (~i ^ ~l)
        addClause(i, 1, p + r - 1, 0); // i -> f <= r <=> (~i ^ r)
    }

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        addClause(x - 1, 1, y - 1, 1); //x -> ~y <=> ~y -> x <=> (~x ^ ~y)
    }

    for(int i = 0; i < M - 1; i++){
        addClause(p + i, 1, p + i + 1, 0); // (f < i) -> (f < i + 1) <=> ~(f < i) ^ (f < i + 1)
    }

    if(solve2SAT(p + M)){
        int k = 0, f = -1;
        for(int i = 0; i < p; i++)
            k += val[i];
        for(int i = p; i < (p + M) && f == -1; i++)
            f =  (val[i] ? i - p + 1 : -1);
        cout << k << " " << f << "\n";
        for(int i = 0; i < p; i++)
            if(val[i])
                cout << i + 1 << " ";
        cout << "\n";
    }
    else
        cout << -1 << "\n";

    return 0;   
}
