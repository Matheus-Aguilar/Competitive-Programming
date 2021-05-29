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
#define MAXN 3650

using namespace std;

int n, b[20], t, dist[MAXN];

void bfs(int s){
    queue<int> q;
    
    q.push(s);
    dist[s] = 0; 

    while(!q.empty()){
        
        int u = q.front();
        q.pop();

        for(int i = 0; i < n; i++){
            
            int k = u + b[i];

            if(k < 0) k = 0;
            if(k > 3600) k = 3600;
        
            if(dist[k] > dist[u] + 1){
                dist[k] = dist[u] + 1;
                q.push(k);
            }
        }
    }
}

int main(){
    optimize;
    
    int T;
    cin >> T;

    while(T--){

        cin >> n >> t;

        for(int i = 0; i < n; i++)
            cin >> b[i];

        ms(dist, INF);

        bfs(0);

        int ans, ext;

        for(int i = t; i <= 3600; i++){
            
            ans = dist[i];

            if(ans != INF){
                ext = i - t;
                break;
            }
        }

        cout << ans << " " << ext << "\n";
    }

    return 0;   
}
