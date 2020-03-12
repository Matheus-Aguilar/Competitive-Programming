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
#define MAXN 1024100

using namespace std;

int a[MAXN];
int segtree[4 * MAXN];
char lazy[4 * MAXN];

int combine(int a, int b){
    return segtree[a] + segtree[b];
}

void build(int node, int start, int end){
    
    lazy[node] = 'X';
    
    if(start == end)
        segtree[node] = a[start];
    else{
        int middle = start + (end - start)/2;
        build(2 * node, start, middle);
        build(2 * node + 1, middle + 1, end);
        segtree[node] = combine(2 * node, 2 * node + 1);
    }
}

void updateValue(int node, int start, int end, char c){
    if(c == 'F')
        segtree[node] = end - start + 1;
    else if(c == 'E')
        segtree[node] = 0;
    else if(c == 'I')
        segtree[node] = end - start + 1 - segtree[node];
}

void updateLazy(int node, char c){
    if(c == 'F' || c == 'E')
        lazy[node] = c;
    else if(c == 'I'){
        if(lazy[node] == 'F') lazy[node] = 'E';
        else if(lazy[node] == 'E') lazy[node] = 'F';
        else if(lazy[node] == 'I') lazy[node] = 'X';
        else lazy[node] = 'I';
    }
}

void push(int node, int start, int end){
    int middle = start + (end - start)/2;
    updateValue(2 * node, start, middle, lazy[node]);
    updateLazy(2 * node, lazy[node]);
    updateValue(2 * node + 1, middle + 1, end, lazy[node]);
    updateLazy(2 * node + 1, lazy[node]);
    lazy[node] = 'X'; //Limpa o lazy
}

void update(int node, int l, int r, int start, int end, char c){
    if(l > r) 
        return;
    if(l == start && r == end){
        updateValue(node, start, end, c); //Atualiza
        updateLazy(node, c);
        return;
    }

    push(node, start, end); //Propago o lazy atualizado
    int middle = start + (end - start)/2;
    //Atualizo os dois filhos
    update(2 * node, l, min(r, middle), start, middle, c);
    update(2 * node + 1, max(l, middle + 1), r, middle + 1, end, c);
    segtree[node] = combine(2 * node, 2 * node + 1); //Atualizo meu valor com base nos filhos
}

int query(int node, int l, int r, int start, int end){
    if(l > r)
        return 0; //Caso impossivel
    if(l == start && r == end)
        return segtree[node];

    push(node, start, end); //Propago o lazy atualizado

    int middle = start + (end - start)/2;
    
    //Calculo meu valor com base nos meus filhos
    return 
        query(2 * node, l, min(r, middle), start, middle) +
        query(2 * node + 1, max(l, middle + 1), r, middle + 1, end);
}

int main(){
    optimize;

    int tests;
    cin >> tests;

    for(int t = 1; t <= tests; t++){
        int m;
        cin >> m;
        string land = "";
        while(m--){
            int t;
            string s;
            cin >> t >> s;
            while(t--){
                land += s;
            }
        }

        int n = land.size();

        for(int i = 0; i < n; i++)
            a[i] = (int)(land[i] - '0');

        build(1, 0, n - 1);

        int q;
        cin >> q;

        cout << "Case " << t << ":\n";

        int cont = 1;

        while(q--){
            char type;
            int l, r;
            cin >> type >> l >> r;

            if(type == 'S')
                cout << "Q" << cont++ << ": " << query(1, l, r, 0, n - 1) << "\n";
            else
                update(1, l, r, 0, n - 1, type);
        }
    }
    
    return 0;   
}
