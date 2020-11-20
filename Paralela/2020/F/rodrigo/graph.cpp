#include <bits/stdc++.h>
#include "omp.h"
using namespace std;

/* Maximum size (in char) for neighbors and compute lists */
#define MAX 100

typedef struct {
//   int id;
  float value;
  vector<int> neighbors;
} Node;

float busca(const unordered_map<int,Node>& graph, int curr) {
    float ans = graph.at(curr).value;
    bool mudou = true;

    while(graph.at(curr).neighbors.size() > 0 && mudou) {
        mudou = false;
        int next = curr;
        float maior = 0.0;
        for(int i=0; i<graph.at(curr).neighbors.size(); i++) {
            int neighbor = graph.at(curr).neighbors[i];
            if(graph.find(neighbor) == graph.cend())
                continue;
            mudou = true;
            // cerr << curr << ": " << neighbor << " x " << maior << endl; 
            if(maior < graph.at(neighbor).value) {
                maior = graph.at(neighbor).value;
                next = neighbor;
            }
        }
        ans += maior;
        curr = next;
        // cerr << next << " ui " << ans << endl;
    }

    return ans;
}

/* Main program - calls read input, computes sum for each node in the list, prints output */
int main() {

    int n; cin>>n;
    unordered_map<int,Node> graph(n);
    vector<int> start_ids;

    cin.ignore();
    string runs;
    getline(cin, runs);

    string start_node;
    stringstream ss(runs);
    while(getline(ss, start_node, ' '))
        start_ids.push_back(stoi(start_node));

    for(int i=0; i<n; i++) {
        string s;
        string neighbor;
        int id; float value;
        getline(cin,s);
        stringstream sss(s);
        // sss >> id >> value;
        // graph[id] = {value, vector<int>()};
        int j=0;
        while(sss >> neighbor) {
            if(j==0) id = stoi(neighbor);
            else if(j == 1) {
                value = stof(neighbor);
                graph[id] = {value, vector<int>()};
            }
            else {
                graph[id].neighbors.push_back(stoi(neighbor));
            }
            j++;
        }
    }

    // cerr << n;
    // for(int i=0; i<start_ids.size(); i++) {
    //     cerr << " " << start_ids[i];
    // }
    // cerr << "\n";

    // for(auto &c: graph) {
    //     cerr << c.first << " " << c.second.value << ",";
    //     for(int j=0; j<c.second.neighbors.size(); j++)
    //         cerr << " " << c.second.neighbors[j];
    //     cerr << "\n";
    // }
    
    vector<float> ans(start_ids.size());

    #pragma omp parallel for
    for(int i=0; i<start_ids.size(); i++) {
        ans[i] = busca(graph, start_ids[i]);
    }

    for(int i=0; i<start_ids.size(); i++) {
        printf("%d: %f\n", start_ids[i], ans[i]);
    }

  return 0;
}
