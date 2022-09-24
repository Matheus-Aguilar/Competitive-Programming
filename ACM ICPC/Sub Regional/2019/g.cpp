#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000
#define pii pair<int, int>
#define MAXN 110

using namespace std;

int n;
long double pu[MAXN], pv[MAXN], cost[MAXN][MAXN], minv[MAXN];
int pairV[MAXN], way[MAXN];
bool used[MAXN];

//Algoritmo hungaro do macacario do ITA
void hungarian(){
    memset(pairV, 0, sizeof(pairV));
    for(int i = 1, j0 = 0; i <= n; i++){
        pairV[0] = i;
        fill(minv, minv + MAXN, INF);
        memset(used, false, sizeof(used));
        do{
            used[j0] = true;
            int i0 = pairV[j0], j1;
            long double delta = INF;

            for(int j = 1; j <= n; j++){
                if(used[j]) continue;
                long double cur = cost[i0][j] - pu[i0] - pv[j];
                if(cur < minv[j])
                    minv[j] = cur, way[j] = j0;
                if(minv[j] < delta)
                    delta = minv[j], j1 = j;
            }
            for(int j = 0; j <= n; j++){
                if(used[j])
                    pu[pairV[j]] += delta, pv[j] -= delta;
                else
                    minv[j] -= delta;
            }
            j0 = j1;
        } while(pairV[j0] != 0);

        do{
            int j1 = way[j0];
            pairV[j0] = pairV[j1];
            j0 = j1;
        } while(j0);
    }
}

int main(){
    optimize;
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int aux;
            cin >> aux;
            cost[i][j] = -log2(aux);
        }
    }

    hungarian();

    for(int i = 1; i <= n; i++)
        cout << pairV[i] << " ";
    cout << "\n";

    return 0;   
}
