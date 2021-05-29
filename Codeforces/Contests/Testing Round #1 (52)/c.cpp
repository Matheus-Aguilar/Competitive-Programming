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
#define MAXN 2000100

using namespace std;

ll segtree[4 * MAXN];
ll lazy[4 * MAXN];
ll a[MAXN];

ll combine(ll a, ll b){
    return min(a, b);
}

void build(int node, int start, int end){
    lazy[node] = 0;
    
    if(start == end){
        segtree[node] = a[start];
        return;
    }

    int middle = start + (end - start)/2;

    build(2 * node, start, middle);
    build(2 * node + 1, middle + 1, end);

    segtree[node] = combine(segtree[2 * node], segtree[2 * node + 1]);
}

void push(int node){
    //Me atualizo
    segtree[node] += lazy[node];

    //Atualizo o lazy
    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];
    lazy[node] = 0;
}

void update(int node, int start, int end, int l, int r, int v){
    
    push(node);

    if(l > r) 
        return;
    if(l == start && r == end){
        lazy[node] = v; //Posso adicionar direto, pois ja dei push em cima
        push(node); //Atualizo
        return;
    }

    //Atualizo meus filhos
    int middle = start + (end - start)/2;
    update(2 * node, start, middle, l, min(middle, r), v);
    update(2 * node + 1, middle + 1, end, max(middle + 1, l), r, v);

    segtree[node] = combine(segtree[2 * node], segtree[2 * node + 1]);
}

ll query(int node, int start, int end, int l, int r){
    
    push(node);

    if(l > r)
        return INFLL; //Caso impossivel
    if(l == start && r == end)
        return segtree[node]; //Cheguei no intervalo
    int middle = start + (end - start)/2;
    return combine(
        query(2 * node, start, middle, l, min(middle, r)),
        query(2 * node + 1, middle + 1, end, max(middle + 1, l), r)
    );
}

int main(){
    optimize;

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    build(1, 0, n - 1);

    int m;
    cin >> m;
    cin.ignore();
    while(m--){
        stringstream ss;
        string s;
        getline(cin, s);
        ss << s;
        
        int q[4] = {INF, INF, INF, INF};
        int i = 0;

        while(ss >> q[i++]);

        if(q[2] == INF){
            if(q[0] <= q[1]){
                cout << query(1, 0, n - 1, q[0], q[1]) << "\n";
            }
            else{
                cout << combine(query(1, 0, n - 1, 0, q[1]), query(1, 0, n - 1, q[0], n - 1)) << "\n";
            }
        }
        else{
            if(q[0] <= q[1]){
                update(1, 0, n - 1, q[0], q[1], q[2]);
            }
            else{
                update(1, 0, n - 1, 0, q[1], q[2]);
                update(1, 0, n - 1, q[0], n - 1, q[2]);
            }
        }
    }
    
    return 0;   
}
