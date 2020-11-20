#include<bits/stdc++.h>

using namespace std;

/* Maximum size (in char) for neighbors and compute lists */
#define MAX 500

bool ok[MAX];
int n, start[MAX];
float val[MAX], ans[MAX], dp[MAX];
vector<int> adj[MAX];
unordered_map<int, int> pos;

float calc(int u){

	if(u == -1) 
		return 0.0;
	if(!ok[u]){
		int best = -1;

		for(int i = 0; i < (int)adj[u].size(); i++){
			int v = adj[u][i];
			if(v != -1 && (best == -1 || val[v] > val[best]))
				best = v;
		}

		dp[u] = val[u] + calc(best);
	}
	return dp[u];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stringstream ss;
	string s;

	getline(cin, s);

	ss << s;

	ss >> n;

	int cont = 0, aux;

	while(ss >> aux){
		start[cont++] = aux;
	}

	for(int i = 0; i < n; i++){
		
		int id, v;

		getline(cin, s);

		ss.clear();

		ss << s;

		ss >> id >> val[i];

		pos[id] = i;

		while(ss >> v) adj[i].push_back(v);
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < (int)adj[i].size(); j++){
			if(pos.find(adj[i][j]) != pos.end())
				adj[i][j] = pos[adj[i][j]];
			else
				adj[i][j] = -1;
		}
	}

	#pragma omp parallel for
	for(int i = 0; i < cont; i++){
		int aux = (pos.find(start[i]) != pos.end() ? pos[start[i]] : -1);
		ans[i] = calc(aux);
	}

	for(int i = 0; i < cont; i++)
		cout << start[i] << ": " << fixed << setprecision(6) << ans[i] << "\n";

	return 0;
}
