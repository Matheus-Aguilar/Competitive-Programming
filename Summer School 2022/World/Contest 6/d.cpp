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
#define MAXN 2200

using namespace std;

int a0[MAXN], b0[MAXN], a1[MAXN], b1[MAXN], h[MAXN];
bool m1[MAXN][MAXN], m2[MAXN][MAXN][4];

void bfs(int si, int sj){

    queue<pii> q;
    q.emplace(si, sj);

    m1[si][sj] = true;

    while(!q.empty()){

        pii p = q.front();
        q.pop();

        int i = p.first;
        int j = p.second;

        if(i < 1004 && !m2[i][j][0] && !m1[i + 1][j]){
            m1[i + 1][j] = true;
            q.emplace(i + 1, j);
        }
        if(i > 0 && !m2[i][j][1] && !m1[i - 1][j]){
            m1[i - 1][j] = true;
            q.emplace(i - 1, j);
        }
        if(j < 1004 && !m2[i][j][2] && !m1[i][j + 1]){
            m1[i][j + 1] = true;
            q.emplace(i, j + 1);
        }
        if(j > 0 && !m2[i][j][3] && !m1[i][j - 1]){
            m1[i][j - 1] = true;
            q.emplace(i, j - 1);
        }
    }
}

int main(){
    optimize;

    int n, w;
    
    while(cin >> n){

        if(n == 0)
            break;

        ms(m1, false);
        ms(m2, false);
        
        for(int i = 0; i < n; i++){
            
            cin >> a0[i] >> b0[i] >> a1[i] >> b1[i] >> h[i];
            
            a0[i] += 502;
            a1[i] += 502;
            b0[i] += 502;
            b1[i] += 502;

            if(a0[i] > a1[i])
                swap(a0[i], a1[i]);
            if(b0[i] > b1[i])
                swap(b0[i], b1[i]);
        }

        cin >> w;

        for(int i = 0; i < n; i++){
            if(h[i] >= w){
                if(a0[i] == a1[i]){
                    for(int j = b0[i]; j < b1[i]; j++){
                        m2[a0[i] - 1][j][0] = true;
                        m2[a0[i]][j][1] = true;
                    }
                }
                else{
                    for(int j = a0[i]; j < a1[i]; j++){
                        m2[j][b0[i] - 1][2] = true;
                        m2[j][b0[i]][3] = true;
                    }
                }
            }
        }

        bfs(0, 0);

        int ans = 0;

        for(int i = 0; i < 1005; i++){
            for(int j = 0; j < 1005; j++){
                if(!m1[i][j]){
                    ans++;
                }
            }      
        }

        cout << ans << "\n";
    }
    
    return 0;   
}
