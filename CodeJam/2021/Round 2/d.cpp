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
#define MAXN 15

using namespace std;

unordered_map<string, int> dist;

int r, c, f, s;

void bfs(string &s, string &d){
    
    queue<string> q;
    string u, v;
    bool found = false;

    q.push(s);
    dist[s] = 0;


    while(dist.find(d) == dist.end()){
        
        u = q.front();
        q.pop();

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(i > 0){
                    
                    v = u;
                    swap(v[i * c + j], v[(i - 1) * c + j]);

                    if(dist.find(v) == dist.end()){
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
                if(i < r - 1){
                    v = u;
                    swap(v[i * c + j], v[(i + 1) * c + j]);

                    if(dist.find(v) == dist.end()){
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
                if(j > 0){
                    v = u;
                    swap(v[i * c + j], v[i * c + j - 1]);

                    if(dist.find(v) == dist.end()){
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
                if(j < c - 1){
                    v = u;
                    swap(v[i * c + j], v[i * c + j + 1]);

                    if(dist.find(v) == dist.end()){
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
                
                v = u;
                v[i * c + j] = (v[i * c + j] == 'G' ? 'M' : 'G'); 

                if(dist.find(v) == dist.end()){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
    }
}

int main(){
    optimize;

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){

        cin >> r >> c >> f >> s;        

        string s = "", d = "", aux;

        for(int i = 0; i < r; i++){
            cin >> aux;
            s += aux;
        }

        for(int i = 0; i < r; i++){
            cin >> aux;
            d += aux;
        }

        dist.clear();

        bfs(s, d);

        cout << "Case #" << t << ": " << dist[d] << "\n";
    }
    
    return 0;   
}
