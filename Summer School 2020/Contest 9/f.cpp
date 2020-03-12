#include<bits/stdc++.h>

using namespace std;

void dfs(int i, int root, vector<unordered_set<int>> &adj, vector<int> &tam, vector<bool> &visit){
    
    visit[i] = true; //Marca como visitado
    
    //Visita os vizinhos e acrescenta no tamanho da subarvore de i
    for(auto v:adj[i]){
        if(!visit[v]){
            dfs(v, root, adj, tam, visit);
            tam[i] += tam[v];
        }
    }

    tam[i]++; //Conta o proprio vertice na subarvore
}

int checkCentroid(int i, vector<unordered_set<int>> &adj, vector<int> &tam, int n){

    int heaviest = 0;
    int heaviestChild = -1;
    
    for(auto v:adj[i]){
        if(tam[v] < tam[i]){
            if(tam[v] > n/2){
                if(tam[v] > heaviest){
                    heaviest = tam[v];
                    heaviestChild = v;
                }
            }
        }
    }

    if(heaviestChild == -1)
        return i;
    else
        return checkCentroid(heaviestChild, adj, tam, n);
}

int getCentroid(int ini, vector<unordered_set<int>> &adj, vector<int> &tam, int n){
    vector<bool> visit(adj.size(), false);
    fill(tam.begin(), tam.end(), 0);
    dfs(ini, ini, adj, tam, visit);
    return checkCentroid(ini, adj, tam, n);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        vector<unordered_set<int>> adj(n + 1);

        for(int i = 0; i < n - 1; i++){
            int a, b;
            cin >> a >> b;
            adj[a].insert(b);
            adj[b].insert(a);
        }

        
        vector<int> tam(adj.size(), 0);

        int guess = getCentroid(1, adj, tam, n);
        int ans;

        while(true){
            cout << 1 << " " << guess << endl;
            cin >> ans;    

            if(ans == -2){
                return 0;
            }
            else if(ans == -1){
                
                cout << 2 << " " << guess << endl;
                cin >> ans;
                
                if(ans == 1)
                    break;
                else if(ans == -2)
                    return 0;
            }

            adj[ans].erase(guess);
            guess = getCentroid(ans, adj, tam, tam[ans]);
        }
    }
}