#include<bits/stdc++.h>

using namespace std;

struct UnionFind{
    vector<int>parent;
    UnionFind(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    void MergeSets(int a, int b){
        parent[GetParent(a)] = GetParent(b);
    }
    int GetParent(int a){
        if(a == parent[a]) return a;
        parent[a] = GetParent(parent[a]);
        return parent[a];
    }
};

int main(){
    int n, m, q;
    bool first = true;

    while(scanf("%d%d%d", &n, &m, &q) == 3){
        
        if(!first) printf("\n");
        else first = false;

        UnionFind uf(n);
        while(m--){
            int a, b;
            scanf("%d%d", &a, &b);
            uf.MergeSets(a - 1, b -1);
        }
        while(q--){
            int a, b;
            scanf("%d%d", &a, &b);
            printf("%c\n", (uf.GetParent(a - 1) == uf.GetParent(b - 1)?'S':'N'));
        }
    }
}