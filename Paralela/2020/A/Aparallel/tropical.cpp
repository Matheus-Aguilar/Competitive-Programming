#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> colors;

pair<int, vector<int>> findPath(vector<bool>& v, set<int>& added_colors, int node) {
	v[node] = true;

    bool new_color = false;

    if (added_colors.find(colors[node]) == added_colors.end()) {
        added_colors.insert(colors[node]);
        new_color = true;
    }

    int max_colors = 0;
    vector<int> path;

	for (int i = 0; i < graph[node].size(); ++i) {
        pair<int, vector<int>> new_path;

		if (!v[graph[node][i]]) {
			new_path = findPath(v, added_colors, graph[node][i]);

            if (new_path.first > max_colors) {
                max_colors = new_path.first;
                path = new_path.second;
            }

            v[graph[node][i]] = false;
        }
    }

    path.emplace_back(node);

    if (new_color) {
        added_colors.erase(colors[node]);
        return { 1 + max_colors, path };
    }
    else
        return { max_colors, path };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n_vertices, n_colors, n_edges;

    cin >> n_vertices >> n_colors;

    graph.resize(n_vertices);
    colors.resize(n_vertices);

    for (int i = 0; i < n_vertices; ++i)
        cin >> colors[i];

    cin >> n_edges;

    for (int i = 0; i < n_edges; ++i) {
        int e1, e2;

        cin >> e1 >> e2;

        graph[e1].emplace_back(e2);
        graph[e2].emplace_back(e1);
    }

    int max_colors = INT_MIN;
    vector<int> best_path;

    vector<pair<int, vector<int>>> new_path(n_vertices);
    vector<set<int>> added_colors(n_vertices);
    vector<vector<bool>> visited(n_vertices, vector<bool>(n_vertices, false));


    #pragma omp parallel for
    for (int i = 0; i < n_vertices; ++i) {
        new_path[i] = findPath(visited[i], added_colors[i], i);
    }

    for(int i = 0; i < n_vertices; ++i){
        if(new_path[i].first > max_colors){
            max_colors = new_path[i].first;
            best_path = new_path[i].second;
        }    
    }

    reverse(best_path.begin(), best_path.end());

    cout << best_path[0];

    for (size_t i = 1; i < best_path.size(); ++i)
        cout << '-' << best_path[i];
    
    cout << '\n' << max_colors << '\n';
}
