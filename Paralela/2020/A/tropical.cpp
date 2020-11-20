#include <iostream>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <climits>

using namespace std;

int nCores = 0;
int nVertices = 0;
int nArestas = 0;
int no_of_vert = 0;
int contCor = 0;

vector<int> caminhoTropical;
vector<int> caminho;
vector<pair<int, int>> arvoreGeradora;

struct part
{
    vector<pair<int, int>> spanning;
    vector<pair<int, int>> inc_ed;
    vector<pair<int, int>> exc_ed;
};

vector<part> partitions;
vector<pair<int, int>> current_span;

class graph{
	public:
	    int Vertex;
	    vector<vector<int>> adj_mat;
	    vector<int> cores;
	    
	    graph(int vertex)
	    {
	    	Vertex = vertex;
	        for(int i = 0; i < Vertex; i++){
	        	vector<int> aux;
	            for(int j = 0; j < Vertex; j++){
	                aux.push_back(0);
				}
				adj_mat.push_back(aux);
            }
	                
	        for(int i = 0; i < Vertex; i++)
	           cores.push_back(0);
	    }
	    
	    void add_edge(int u, int v)
	    {
	        adj_mat[u][v] = adj_mat[v][u] = 1;
	    }
};

int find_min_key(vector<int> arr, int V, vector<bool> mstset)
{
    int min_key=INT_MAX, min_index=-1;
    for(int i=0;i<V;i++)
    {
        if(arr[i]<min_key && mstset[i]==false){
            min_key=arr[i];
            min_index=i;
        }
    }
    return min_index;
}

bool is_cycle(vector<vector<int>> mat,int src, int V)//verificar se o gr?fico formado ? c?clico ou n?o
{
    map<int,bool> visited;
    queue<int> traverse;
    map<int,int> parent;
    parent[src]=src;
    visited[src]=true;
    traverse.push(src);
    while(!traverse.empty())
    {
        int node=traverse.front();
        traverse.pop();
        for(int i=0;i<V;i++)
            if(mat[node][i]>0)
            {
                if(!visited[i])
                {
                    traverse.push(i);
                    visited[i]=true;
                    parent[i]=node;
                }
                else if(visited[i]==true && i!=parent[node])
                    return 1; //ciclo
            }
    }
    return 0;
}

int Prim_ST(graph G, vector<pair<int,int>> include_edges, vector<pair<int,int>> exclude_edges)
{
    int V = G.Vertex;
	           
    vector<vector<int>> new_mat;
    vector<vector<int>> mat_cycle;
    
    for(int i = 0; i < V; i++){
    	vector<int> aux;
        for(int j = 0; j < V; j++){
            aux.push_back(0);
		}
		mat_cycle.push_back(aux);
    }
    
    for(int i = 0; i < V; i++){
    	vector<int> aux;
        for(int j = 0; j < V; j++){
            aux.push_back(G.adj_mat[i][j]);
		}
		new_mat.push_back(aux);
    }
    
    int u1,v1;
    for(vector<pair<int, int>>::iterator it=exclude_edges.begin(); it!=exclude_edges.end();it++)
    {
        u1=(*it).first;
        v1=(*it).second;
        new_mat[u1][v1]=new_mat[v1][u1]=INT_MIN;
    }
    
    int parent[V];
    vector<int> key(V);
    vector<bool> mstset(V);
    for(int i=0;i<V;i++)
    {
        key[i]=INT_MAX;
        mstset[i]=false;
        parent[i]=nVertices;
    }
    
    int root;
    root= 0;
    parent[root]=-1;
    
    int vertex_must_include[V];
    map<int, int> parent_included_vertex;
    
    for(int m=0;m<V;m++)
        vertex_must_include[m]=false;
    if(!include_edges.empty())
    {
        for(vector<pair<int, int>>::iterator it=include_edges.begin(); it!=include_edges.end();it++)
        {
            u1=(*it).first;
            v1=(*it).second;
            vertex_must_include[u1]=vertex_must_include[v1]=true;
            parent_included_vertex[v1]=u1;
            parent_included_vertex[u1]=100;
        }
    }
    
    key[root]=0;
    parent[root]=-1;
    for(int c=0;c<V;c++)
    {
        int u=find_min_key(key, V, mstset);
        if(u==-1) //desconectado
        {
            return -1;
        }
        mstset[u]=true;
        if(parent[u] > 0)
        	mat_cycle[parent[u]][u]=new_mat[parent[u]][u];
        no_of_vert++;
        for(int v=0;v<V;v++)
        {
            if(new_mat[u][v]>0 && mstset[v]==false && new_mat[u][v]< key[v])
            {
                
                if(vertex_must_include[v] && parent_included_vertex[v]!=100 && parent_included_vertex[v]!=u)
                {
                    int x=parent_included_vertex[v];
                    if(parent[x]!=nVertices)
                        continue;
                }
                //para verificar se o ciclo se formou ou n?o
                int prev=mat_cycle[u][v];
                mat_cycle[u][v]=new_mat[u][v];
                
                bool cycle=is_cycle(mat_cycle, root, V);
                if(!cycle)
                {
                    parent[v]=u;
                    key[v]=new_mat[u][v];
                }
                mat_cycle[u][v]=prev;
            }
        }
    }
    
    int tot_cost=0;
    for(int i=1;i<V;i++){
        int x=parent[i];
        tot_cost+=new_mat[x][i];
        current_span.push_back(make_pair(x, i));
    }
    return tot_cost;
}

void exibirVetor(vector<int> l)
{
    for(auto i: l)
    {
    	if(i == l.back())
    		cout<<i;
    	else
        	cout<<i<<"-";
    }
    cout<<endl;
}

bool buscaSequencial(vector<int> l, int ch){
	for(std::vector<int>::iterator it = l.begin(); it != l.end(); it++)
		if(ch == *it) return true;
	return false;
}

vector<int> buscaAresta(int vert){
	vector<int> aux;
	for(std::vector<std::pair<int, int>>::iterator it = arvoreGeradora.begin(); it != arvoreGeradora.end(); it++){
		pair<int, int> par = *it;
		if(vert == par.first) aux.push_back(par.second);
		if(vert == par.second) aux.push_back(par.first);
	}
	return aux;
}

int coresConjunto(vector<int> l, graph G){
	vector<int> cor;
	
	for(std::vector<int>::iterator it = l.begin(); it != l.end(); it++){
		if(!buscaSequencial(cor, G.cores[*it])){
			cor.push_back(G.cores[*it]);
		}
	}
	return cor.size();
}

bool deep(int vertice, vector<int> hist, graph G)
{
	bool fim = true;
	hist.push_back(vertice);
	vector<int> aux = buscaAresta(vertice);
	
    for(std::vector<int>::iterator it = aux.begin(); it != aux.end(); it++){
    	if(!buscaSequencial(hist, *it)){
    		fim = false;
			if(deep(*it, hist, G)){
				return true;
			}
		}
	}
	
	if(fim){
		int nCor = coresConjunto(hist, G);
		if(nCor == nCores){
			exibirVetor(hist);
			cout<<nCor;
			return true;
		}
		else if(nCor > contCor){
			contCor = nCor;
			caminho = hist;
		}
		return false;
	}
	
    hist.pop_back();
    
    return false;
}

bool caminhoTropi(graph G){
	for (int i = 0; i < nVertices; i++)
    {
		vector<int> historico;
		historico.push_back(i);
	    vector<int> vertices = buscaAresta(i);
	    
		for(std::vector<int>::iterator it = vertices.begin(); it != vertices.end(); it++){
			if(deep(*it, historico, G)){
				return true;
			}
		}
		
		historico.pop_back();
	}
	return false;
}

bool create_partitions(graph G)
{
    while(true)
    {
    	part P;
        vector<part>::iterator iter;
        for(vector<part>::iterator it=partitions.begin();it!=partitions.end();it++)
        {
            iter=it;
        }
        P.spanning=(*iter).spanning;
        P.exc_ed=(*iter).exc_ed;
        P.inc_ed=(*iter).inc_ed;
        partitions.erase(iter);
        
        vector<pair<int, int>> stree = P.spanning;
        vector<pair<int, int>>::iterator it1;
        vector<pair<int, int>>::iterator it2;
        
        arvoreGeradora = stree;
        
        if(caminhoTropi(G)){
			return true;
		}
        
        vector<pair<int, int>> included_edges;
        vector<pair<int, int>> excluded_edges;
        included_edges=P.inc_ed;
        pair<int, int> ex_edge;
        
        int j;
        for(j = 0; j < stree.size(); j++)
        {
            if(included_edges.empty())
                break;
            if(stree[j].first!=included_edges[j].first && stree[j].second!=included_edges[j].second)
            {
                break;
            }
        }
        int cost;
        it2= stree.begin()+ j;
        int u1,v1;
        for(it1=it2; it1!=stree.end(); it1++)
        {
            part new_p;
            u1=(*it1).first;
            v1=(*it1).second;
            ex_edge.first=u1;
            ex_edge.second=v1;
            excluded_edges=P.exc_ed;
            excluded_edges.push_back(ex_edge);
            current_span.clear();
            cost = Prim_ST(G, included_edges, excluded_edges);
            if(cost > 0)
            {
                new_p.spanning=current_span;
                new_p.inc_ed=included_edges;
                new_p.exc_ed=excluded_edges;
                partitions.push_back(new_p);
            }
            included_edges.push_back(ex_edge);
        }
        
        if(partitions.empty()){
            return false;
        }
    }
}

int main() {
    scanf("%i %i", &nVertices, &nCores);
    
    graph G {nVertices};
    
    for	(int i = 0; i < nVertices; i++){
		int cor;
		scanf("%i", &cor);
		G.cores[i] = cor;
	}
    
    scanf("%i", &nArestas);
    
    for	(int i = 0; i < nArestas; i++){
    	int u1, v1;
		scanf("%i %i", &u1, &v1);
        G.add_edge(u1, v1);
	}
	
	vector<pair<int, int>> incl;
    vector<pair<int, int>> excl;
    incl.clear();
    excl.clear();
    Prim_ST(G, incl, excl);
    part p;
    incl.clear();
    excl.clear();
    p.exc_ed=excl;
    p.inc_ed=incl;
    p.spanning=current_span;
    partitions.push_back(p);
    
	if(!create_partitions(G)){
		exibirVetor(caminho);
		cout<<contCor<<endl;
	}
	
    return 0;
}
