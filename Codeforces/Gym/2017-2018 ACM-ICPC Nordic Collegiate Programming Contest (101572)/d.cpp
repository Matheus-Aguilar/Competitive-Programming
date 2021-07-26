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
#define MAXN 100100

using namespace std;

int n, k, a[MAXN];
int adj[(1 << 20)][20];

bool visit[(1 << 20)];
int dist[(1 << 20)];

int calc(int x, int y){
    return k - __builtin_popcount(x ^ y);
}

int convert(string &s){
    int val = 0;

    for(int i = 0; i < s.size(); i++){
        val <<= 1;
        if(s[i] == '1')
            val |= 1;
    }

    return val;
}

string binstr(int v){
    string s = "";

    for(int i = 0; i < k; i++){
        if(v & 1)
            s += '1';
        else
            s += '0';
        v >>= 1;
    }

    reverse(all(s));
    return s;
}

void build(){
    for(int i = 0; i < (1 << k); i++){
        for(int j = 0; j < k; j++){
            int v = (i ^ (1 << j));    
            adj[i][j] = v;
        }
    }
}

void bfs(){
    
    ms(dist, INF);

    queue<int> q;

    for(int i = 0; i < n; i++){
        dist[a[i]] = 0;
        visit[a[i]] = true;
        q.push(a[i]);
    }

    while(!q.empty()){
        
        int u = q.front();
        q.pop();

        for(int i = 0; i < k; i++){
            int v = adj[u][i];
        
            if(!visit[v]){
                dist[v] = dist[u] + 1;
                visit[v] = true;
                q.push(v);
            }
        }
    }
}

int main(){
    optimize;

    cin >> n >> k;

    build();

    string s;

    for(int i = 0; i < n; i++){
        cin >> s;
        a[i] = convert(s);
    }

    sort(a, a + n);
    n = unique(a, a + n) - a;

    bfs();

    int best = 0;

    for(int i = 1; i < (1 << k); i++){
        if(dist[best] < dist[i]){
            best = i;
        }
    }

    cout << binstr(best) << "\n";

    return 0;   
}
