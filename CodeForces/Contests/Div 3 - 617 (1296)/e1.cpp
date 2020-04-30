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

bool dfs(int start, vector<vector<int>> &adj, vector<int> &colors){
	stack<int> s;
	s.push(start);
	colors[start] = 0;
	while(!s.empty()){
		int u = s.top();
		s.pop();
		for(int v:adj[u]){
			if(colors[u] == colors[v]) return false;
			else if(colors[v] == -1){
				colors[v] = !colors[u];
				s.push(v);
			}
		}
	}
	return true;
}

bool bipartite(vector<vector<int>> &adj, vector<int> &colors){
	for(int i = 0; i < adj.size(); i++){
		if(colors[i] == -1){
			if(!dfs(i, adj, colors)) return false;
		}
	}
	return true;
}

int main(){
	optimize;
	
	int n;
	string s;
	cin >> n >> s;

	vector<vector<int>> adj(n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			if(s[j] > s[i]){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	vector<int> colors(n, -1);

	if(bipartite(adj, colors)){
		cout << "YES" << "\n";
		for(int i = 0; i < n; i++)
			cout << colors[i];
		cout << "\n";
	}
	else{
		cout << "NO" << "\n";
	}

	return 0;   
}
