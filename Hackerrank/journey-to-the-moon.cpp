#include<bits/stdc++.h>
#define inf 1000000007

using namespace std;

long long int p = 0;

vector<long long int> fam;
long long int viz[100001] = {0};
long long int numM[100001] = {0};
map<long long int, list<long long int>> adj;

void preencheFam(long long int id, long long int cont){
    fam[id] = cont;
    numM[cont]++;

    for(auto i:adj[id]){
        if(fam[i] == -1)
            preencheFam(i, cont);
    }
}

int main(){
    long long int n, p;
    cin >> n >> p;
    long long int cont = 0;
    for(long long int i = 0; i < n; i++)
        fam.push_back(-1);
    while(p--){
        long long int a, b;
        cin >>a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(long long int i = 0; i < n; i++){
        if(fam[i] == -1){
            stack<long long int> aux;
            aux.push(i);

            long long int j = i;
            while(!aux.empty()){
                if(!adj[j].empty()){
                    aux.push(adj[j].front());
                    adj[j].pop_front();
                    j = aux.top();
                }
                else{
                    fam[aux.top()] = cont;
                    aux.pop();
                    if(!aux.empty())
                        j = aux.top();
                }
            }
            cont++;
        }
    }

    for(long long int i = 0; i < n; i++)
        numM[fam[i]]++;

    long long int res = (n * (n -1))/2;
    for(long long int i = 0; i < cont; i++)
        res -= (numM[i] * (numM[i] - 1))/2;

    cout << res << endl;
}