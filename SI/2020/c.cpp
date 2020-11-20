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
#define MAXN 30

using namespace std;

long double p[MAXN][MAXN][MAXN];
bool v[MAXN][MAXN][MAXN];
int moves[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Pos{
    int x, y, h;
    Pos(int _x = 0, int _y = 0, int _h = 0) : x(_x), y(_y), h(_h) {}
    bool operator<(const Pos &pos) const{
        if(h != pos.h) return h < pos.h;
        if(x < pos.x) return x < pos.x;
        return y < pos.y;
    }
};

void precalc(){
    
    for(int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++)
            for(int k = 0; k < MAXN; k++)
                p[i][j][k] = v[i][j][k] = 0;
    
    p[10][10][0] = 1.0L;
    v[10][10][0] = true;

    queue<Pos> q;
    q.emplace(10, 10, 0);

    while(!q.empty()){
        Pos cur = q.front();
        q.pop();

        if(cur.h < 10){
            for(int i = 0; i < 4; i++){
                int x = cur.x + moves[i][0];
                int y = cur.y + moves[i][1];
                int h = cur.h + 1;
                
                if(!v[x][y][h]) 
                    q.emplace(x, y, h);

                v[x][y][h] = true;
                p[x][y][h] += p[cur.x][cur.y][cur.h]/4.0L;
                
            }
        }
    }
}

int main(){
    optimize;

    precalc();

    int n;
    cin >> n;

    while(n--){
        int t;
        cin >> t;

        long double sum = 0.0L;

        for(int i = 0; i < t; i++){
            int h, x, y;
            cin >> h >> x >> y;
            sum += (1.0L - sum) * p[x + 10][y + 10][h];
        }

        cout << fixed << setprecision(3) << sum << "\n";
    }

    return 0;   
}
