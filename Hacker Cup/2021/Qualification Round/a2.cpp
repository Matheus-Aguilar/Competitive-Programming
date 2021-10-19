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

using namespace std;

void floyd(vector<vector<int>> &adj, int n){

    for(int i = 0; i < n; i++)
        adj[i][i] = 0;

    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main(){
    optimize;
    
    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){
        
        string s;
        cin >> s;

        vector<int> f(26, 0);
        vector<vector<int>> adj(26, vector<int>(26, INF));

        for(int i = 0; i < s.size(); i++){
            f[s[i] - 'A']++;
        }

        int k;
        cin >> k;

        for(int i = 0; i < k; i++){
            char a, b;
            cin >> a >> b;
            adj[a - 'A'][b - 'A'] = 1;
        }

        floyd(adj, 26);

        int best = INF;

        for(int i = 0; i < 26; i++){
            int cost = 0;
            for(int j = 0; j < 26; j++){
                if(adj[j][i] == INF && f[j] != 0){
                    cost = INF;
                    break;
                }
                cost += adj[j][i] * f[j];
            }
            best = min(best, cost);
        }

        cout << "Case #" << t << ": " << (best == INF ? -1 : best) << "\n";
    }

    return 0;   
}
