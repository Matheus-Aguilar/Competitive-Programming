#include <bits/stdc++.h>
using namespace std;

#define MAX 100

typedef struct {
  int id;
  float value;
  char neighbors[MAX];
} Node;

unordered_map<int, int> node_id_cache;

unordered_map<int,float> pd;

Node* read_input(char* fname, int *n, char* list) {  
  Node* data = NULL;
  FILE *fl = NULL;
  
  if (fname == NULL) 
    fl = stdin;
  else 
    fl = fopen(fname, "r");
  
  fscanf(fl, "%d %[^\n]", n, list);
  
  if (*n > 1)
    data = (Node*) malloc ((*n)*sizeof(Node));
  
  for(int i = 0; i < *n; i++) {
    fscanf(fl, "%d %f %[^\n]", &data[i].id, &data[i].value, data[i].neighbors);
    node_id_cache[data[i].id] = i;
  }
  
  fclose(fl);

  return data;
}

inline int find_by_id(int id){
  auto it = node_id_cache.find(id);

  if (it == node_id_cache.end())
    return -1;

  return it->second;
}

float get_costly(Node *g, int id) {
  char *t;
  int idmax = -1;
  float max = 0;
  char *auxptr;
  
  int nd = find_by_id(id);

  if(nd < 0)
    return max;

  #pragma omp critical
  {
  if(pd.find(id) != pd.end())
    return pd[id];
  }

  char aux[MAX];
  strcpy(aux, g[nd].neighbors);
  t = strtok_r(aux, " ", &auxptr);

  do {
    int d = find_by_id(atoi(t));
    if (d >= 0 && max < g[d].value) {
      max = g[d].value;
      idmax = atoi(t);
    }
  } while ((t = strtok_r(NULL, " ", &auxptr)));

  float r = g[nd].value;

  if(idmax != -1)
    r += get_costly(g, idmax);
  

  #pragma omp critical
  {
  pd[id] = r;
  }
  
  return (r);
}

int main() {
  char *fileN = NULL;
  char computelist[MAX];
  int n = -1;
  Node* input = NULL;

  input = read_input(fileN, &n, computelist);

  vector<int> start_nodes;
  for(char *c = strtok(computelist, " "); c != NULL; c = strtok(NULL, " "))
    start_nodes.push_back(atoi(c));
  
  vector<float> ans(start_nodes.size());

  #pragma omp parallel for
  for(int i=0; i<ans.size(); i++)
    ans[i] = get_costly(input, start_nodes[i]);

  for(int i=0; i<ans.size(); i++)
    printf("%d: %f\n", start_nodes[i], ans[i]);
  
  // free(input);

  return 0;
}
