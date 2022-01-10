#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef vector<vector<bool>> adjacency_matrix;

adjacency_matrix readGraph();

bool testIsomorphism(adjacency_matrix &g1, adjacency_matrix &g2);
bool verifyPermutation(adjacency_matrix &g1, adjacency_matrix &g2, vector<int> &equivalence);
inline void printPermutation(vector<int> &equivalence);

int main(){
    adjacency_matrix g1 = readGraph();
    adjacency_matrix g2 = readGraph();

    if(!testIsomorphism(g1, g2))
        cout << "The graphs are not isomorphic" << endl;

    return 0;
}

bool testIsomorphism(adjacency_matrix &g1, adjacency_matrix &g2){
    vector<int> equivalence(g1.size(), 0);
    vector<int> exchange_counter(g1.size(), 0);
    int exchange_index = 1;
    bool isomorphism_found = false;

    if(g1.size() != g2.size()) return false;

    for(int i = 0; i < equivalence.size(); ++i)
        equivalence[i] = i;

    if(verifyPermutation(g1, g2, equivalence)){
        printPermutation(equivalence);
        return true;
    }
    
    /*
     * Permutations are based on Heap's algorithm, which generates all possible 
     * permutations for a given set of elements. 
     */
    while(exchange_index < g1.size()){
        if(exchange_counter[exchange_index] < exchange_index){
            if(exchange_index % 2 == 0)
                swap(equivalence[0], equivalence[exchange_index]);
            else
                swap(equivalence[exchange_counter[exchange_index]], equivalence[exchange_index]);
            if(verifyPermutation(g1, g2, equivalence)){
                printPermutation(equivalence);
                isomorphism_found = true;
            }

            exchange_counter[exchange_index]++;
            exchange_index = 1;
        }else{
            exchange_counter[exchange_index] = 0;
            exchange_index++;
        }
    }
    return isomorphism_found; 
}

adjacency_matrix readGraph(){
    int vertices, edges, source, destination;

    cin >> vertices;
    adjacency_matrix read(vertices);
    for (int i = 0; i < vertices; ++i)
        read[i].resize(vertices);
    
    cin >> edges;    
    for (int i = 0; i < edges; i++) {
       cin >> source >> destination;
       read[destination][source] = read[source][destination] = true; 
    }

    return read;
}

bool verifyPermutation(adjacency_matrix &g1, adjacency_matrix &g2, vector<int> &equivalence){
    for (int i = 0; i < equivalence.size(); ++i) {
        for (int j = 0; j <= i; ++j) {
            if(g1[i][j] != g2[equivalence[i]][equivalence[j]]) return false;
        }
    }
   return true;
}

inline void printPermutation(vector<int> &equivalence){
    for (auto i : equivalence)
        cout << i << " ";
    cout << endl;
}
