#include<bits/stdc++.h>

using namespace std;

vector<int>adj[50];
bool mat[50][50];
int cont[50];

class Graph{
    public:
        vector<vector<int>> flow; //Contem o fluxo que passa pela aresta
        vector<vector<int>> capacities; //Contem a capacidade residual da aresta
        vector<vector<int>> adj; //Lista de adjacencia dos vertices
        vector<bool> visit; //Array de visitados (para nao ficar alocando toda hora)

        const static int INF = 2147483647; //Infinito

        //Inicializa as variaveis do grafo
        Graph(int size = 0){
            flow.assign(size, vector<int>(size, 0)); //O fluxo inicial de tudo é zero
            capacities.assign(size, vector<int>(size, 0)); //A capacidade inicial de tudo é zero
            adj.resize(size);
            visit.assign(size, false);
        }

        //Cria uma aresta (a, b) com capacidade c
        void addEdge(int a, int b, int c){
            adj[a].push_back(b);
            adj[b].push_back(a);
            capacities[a][b] = c; //As arestas são direcionadas para a capacidade
        }

        //Faz uma busca em profundidade de um vertice ate o sorvedouro
        int DFS(int v, int dest, int flowSize){
            if(v == dest) return flowSize; //Cheguei no sorvedouro
            visit[v] = true; //Marca como visitado
            //Vai para os vizinhos
            for(int i:adj[v]){
                //Só vai se não foi visitado e há capacidade restante na aresta
                if(capacities[v][i] && !visit[i]){
                    //O fluxo é limitado pela aresta de menor capacidade do caminho
                    int residualFlow = DFS(i, dest, min(flowSize, capacities[v][i])); //Fluxo do caminho encontrado
                    //Se houve algum fluxo > 0
                    if(residualFlow){
                        capacities[v][i] -= residualFlow; //Remove a capacidade usada da aresta
                        capacities[i][v] += residualFlow; //"Cria" a aresta de retorno
                        flow[v][i] += residualFlow; //Atualiza o fluxo daquele ponto
                        return residualFlow;
                    }
                }
            }
            return 0;
        }

        //Reseta o array de visitados e faz a DFS
        int DFS(int source, int dest){
            fill(visit.begin(), visit.end(), false);
            return DFS(source, dest, INF);
        }

        //Calcula o fluxo entre cada aresta após achar todos os caminhos aumentantes
        void calculateEdgeFlows(){
            for(int i = 0; i < adj.size(); i++){
                for(int j = 0; j < adj[i].size(); j++){
                    if(flow[i][j] > flow[j][i]){
                        flow[i][j] -= flow[j][i];
                        flow[j][i] = 0;
                    }
                    else{
                        flow[j][j] -= flow[i][j];
                        flow[i][j] = 0;
                    }
                }  
            }
        }

        //Calcula o fluxo maximo e preenche a matriz de fluxo do grafo
        int Ford_Fulkerson(int source, int dest){
            
            while(DFS(source, dest)); //Busca os caminhos aumentantes
            
            int maxFlow = 0; //Fluxo máximo
            
            calculateEdgeFlows(); //Ajusta os valores do fluxos das arestas
            //Acumula os fluxos que a fonte mandou para seu vizinhos
            for(int i:adj[source]) maxFlow += flow[source][i];
            
            //Retorna o valor final
            return maxFlow;
        }
};

int main(){
    int n;

    while(cin >> n){
        for(int i = 0; i < n; i++){ 
            for(int j = 0; j < n; j++)
                mat[i][j] = false;
            cont[i] = 0;
            adj[i].clear();
        }

        for(int i = 0; i < n; i++){
            int a, b;
            cin >> a >> b;
            a--, b--;
            adj[i].push_back(a);
            adj[i].push_back(b);
            mat[i][a] = true;
            mat[i][b] = true;
            cont[a]++;
            cont[b]++;
        }

        int winners = 0;
        for(int i = 0; i < n; i++){
            Graph g(2 * n + 2);
            for(int j = 0; j < n; j++){
                if(i != j){
                    if(mat[i][j]){
                        g.addEdge(n + j, 2 * n + 1, cont[i] - 2>0?cont[i] - 2:0);
                    }
                    else{
                        g.addEdge(n + j, 2 * n + 1, cont[i] - 1>0?cont[i] - 1:0);
                    }
                    if(!mat[j][i])
                        g.addEdge(2 * n, j, 1);
                }
            }

            for(int j = 0; j < n; j++){
                if(!mat[j][i] && i != j) 
                    for(auto k = adj[j].begin(); k != adj[j].end(); k++)
                        g.addEdge(j, *k + n, 1);
            }

            int maxflow = g.Ford_Fulkerson(2 * n, 2 * n + 1);


            // if(i == 23){
            //     for(int j = 0; j < n; j++)
            //         if(!mat[j][i] && i != j)
            //             cerr << j << " " << g.adj[j + n][0].flow << " " << g.adj[j + n][0].C << endl;
            
            //     cerr << endl;

            //     for(auto j:g.adj[2 * n]){
            //         cerr << j.v << " " << j.flow << endl;
            //     }
            // }

            //cerr << i << " " << maxflow << " " << n - cont[i] - 1 << " " << n << " " << cont[i] << endl;
            
            // int sum = 0, sum2 = 0;
            // if(i == 23){
            //     for(int j = 0; j < n; j++)
            //         if(!mat[j][i] && i != j){
            //             for(auto k:adj[j]){
            //                 cerr << j << " " << k << " " << g.adj[j][k + n].flow << endl;
            //             }
            //         }
            // }
            
            if(maxflow < n - cont[i] - 1){
                winners++;
            }
        }

        cout << winners << endl;
    }
}