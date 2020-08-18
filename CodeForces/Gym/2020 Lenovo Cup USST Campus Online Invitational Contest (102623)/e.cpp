#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pli pair<long long int, int>
#define pil pair<int, long long int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

struct myHash{
    size_t operator()(const vector<int> &v) const{
        size_t val = 0, pot = 1;
        for(int i = 0; i < 8; i++){
            val += v[i] * pot;
            pot *= 9;
        }
        return val;
    }
};

int n;
string s;

ll p[8][8];
ll c[8][8];

vector<pil> adj[40320];

vector<int> ord[40320];
unordered_map<vector<int>, int, myHash> m;

int inv[8][8];
int freq[8];

ll cost[40320];
ll dist[40320];

void precalc(){
    int cont = 0;
    vector<int> v = {1,2,3,4,5,6,7,8};
    do{
        ord[cont++] = v;
    } while(next_permutation(all(v)));

    for(int i = 0; i < cont; i++)
        m[ord[i]] = i;


    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(i >= j) continue;
            for(int k = 0; k < cont; k++){
                v = ord[k];
                int p1 = find(all(v), i + 1) - v.begin(), p2 = find(all(v), j + 1) - v.begin();
                swap(v[p1], v[p2]);
                adj[m[ord[k]]].push_back(pil(m[v], c[i][j]));
            }
        }    
    }

    for(int i = 0; i < n; i++){
        int now = s[i] - '1';
        for(int j = 0; j < 8; j++)
            inv[j][now] += freq[j];
        freq[now]++;
    }

    for(int i = 0; i < cont; i++)
        for(int j = 0; j < 8; j++)
            for(int k = 0; k < 8; k++)
                cost[i] += p[ord[i][j] - 1][ord[i][k] - 1] * inv[j][k];
}

void dijkstra(int s){
    
    set<pli> pq;
    
    ms(dist, INF);
    dist[s] = 0;

    pq.insert(pli(0, s));
    while(!pq.empty()){
        
        int u = pq.begin()->second;
        pq.erase(pq.begin());

        for(int i = 0; i < adj[u].size(); i++){

            int v = adj[u][i].first;
            ll w = adj[u][i].second;

            if(dist[v] > dist[u] + w){
                pq.erase(pli(dist[v], v));
                dist[v] = dist[u] + w;
                pq.insert(pli(dist[v], v));
            }
        }
    }
}


int main(){
    optimize;

    cin >> n >> s;

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            cin >> p[i][j];

    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            cin >> c[i][j];

    precalc();
    dijkstra(0);

    ll best = INFLL;

    for(int i = 0; i < 40320; i++){
        if(dist[i] != INFLL)
            best = min(best, cost[i] + dist[i]);
    }

    cout << best << "\n";
    
    return 0;   
}
