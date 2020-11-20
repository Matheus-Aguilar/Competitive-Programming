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
#define MAXN 500
#define MAXM 3000

using namespace std;

/*Dinic do Macacario do ITA*/

int ned, first[MAXN], work[MAXN], dist[MAXN], q[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM];

int solution[MAXN][MAXN];

void init() {
   memset(first, -1, sizeof first);
   ned = 0;
}

void add(int u, int v, int f) {
	to[ned] = v, cap[ned] = f;
	nxt[ned] = first[u];
	first[u] = ned++;
	
	to[ned] = u, cap[ned] = 0;
	nxt[ned] = first[v];
	first[v] = ned++;
}

int dfs(int u, int f, int t) {
	if (u == t) return f;
	for(int &e = work[u]; e != -1; e = nxt[e]) {
		int v = to[e];
		if (dist[v] == dist[u] + 1 && cap[e] > 0) {
			int df = dfs(v, min(f, cap[e]), t);
			if (df > 0) {
				cap[e] -= df;
				cap[e^1] += df;
				return df;
			}
		}
	}
	return 0;
}

bool bfs(int s, int t) {
	memset(&dist, -1, sizeof dist);
	dist[s] = 0;
	int st = 0, en = 0;
	q[en++] = s;
	while (en > st) {
		int u = q[st++];
		for(int e = first[u]; e!=-1; e = nxt[e]) {
			int v = to[e];
			if (dist[v] < 0 && cap[e] > 0) {
				dist[v] = dist[u] + 1;
				q[en++] = v;
			}
		}
	}
	return dist[t] >= 0;
}

int dinic(int s, int t) {
	int result = 0, f;
	while (bfs(s, t)) {
		memcpy(work, first, sizeof work);
		while (f = dfs(s, INF, t)) result += f;
	}
	return result;
}

int main(){
    optimize;

    int l, t, u, v, c, in = 0, out = 0;
    cin >> l >> t;

    init();

    //Fonte
    for(int i = 1; i <= l; i++){
        cin >> c;
        add(0, i, c);
        in += c;
    }

    //Sorvedouro
    for(int i = 1; i <= l; i++){
        cin >> c;
        add(i + l, 2 * l + 1, c);
        out += c;
    }

    //Vertices intermediarios
    for(int i = 0; i < t; i++){
        cin >> u >> v;
        add(u, v + l, INF);
        add(v, u + l, INF);
    }

    //Caminho para si mesmo
    for(int i = 1; i <= l; i++)
        add(i, i + l, INF);

    int maxflow = dinic(0, 2 * l + 1);

    if(in != out || maxflow < out){
        cout << "NO" << "\n";
    }
    else{
        cout << "YES" << "\n";

        for(int i = 1; i <= l; i++){
            for(int e = first[i + l]; e != -1; e = nxt[e]){
                solution[to[e]][i] = cap[e];
            }
        }

        for(int i = 1; i <= l; i++)
            for(int j = 1; j <= l; j++)
                cout << solution[i][j] << " \n"[j==l];
    }
    
    return 0;   
}
