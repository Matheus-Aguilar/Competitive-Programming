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
#define MAXN 510

using namespace std;

int n, adj[MAXN][MAXN], nxt[MAXN][MAXN];
string label[MAXN];
map<string, int> idx;

void print(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << setw(10) << adj[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << setw(10) << nxt[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    optimize;

    ms(adj, INF);
    ms(nxt, -1);

    cin >> n;

    for(int i = 0; i < n; i++){
        string name;
        cin >> name;
        
        idx[name] = i;
        label[i] = name;
    }

    for(int i = 0; i < n; i++){
        string name, import, line;
        int u, v, m;

        cin >> name >> m;
        u = idx[name];

        for(int j = 0; j < m; j++){
            
            cin >> import;
            getline(cin, line);

            stringstream ss;
            ss << line;
            
            while(ss >> name){
                
                if(name.back() == ',') name.pop_back();
                v = idx[name];

                adj[u][v] = 1;
                nxt[u][v] = v;
            }
        }
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(adj[i][j] > adj[i][k] + adj[k][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }    
    }

    //print();
    
    int best = -1;

    for(int i = 0; i < n; i++){
        if(adj[i][i] != INF && (best == -1 || adj[best][best] > adj[i][i])){
            best = i;
        }
    }

    if(best == -1){
        cout << "SHIP IT" << "\n";
    }
    else{
        int u = best;

        do{
            cout << label[u] << " ";
            u = nxt[u][best];
        } while(u != best);

        cout << "\n";
    }

    return 0;   
}
