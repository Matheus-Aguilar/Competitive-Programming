#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

/*CP-Algorithm implementation Kosaraju to solve 2-SAT problem*/

int k;
vector<vector<int>> g, gt;
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

void dfs1(int v) {
    used[v] = true;
    for (int u : g[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : gt[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve_2SAT() {
    used.assign(k, false);
    for (int i = 0; i < k; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(k, -1);
    for (int i = 0, j = 0; i < k; ++i) {
        int v = order[k - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(k / 2, false);
    for (int i = 0; i < k; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

int main(){
    optimize;

    int n, k;
    cin >> k >> n;
    g.resize(k);
    gt.resize(k);

    while(n--){
        int l1, l2, l3; //Lampadas
        char c1, c2, c3; //Cores

        cin >> l1 >> c1 >> l2 >> c2 >> l3 >> c3;

        //Transformar em proposicoes binarias
        //(a & b) | (b & c) | (a & c) = (a | b) & (a | c) & (b | c)
    }
}