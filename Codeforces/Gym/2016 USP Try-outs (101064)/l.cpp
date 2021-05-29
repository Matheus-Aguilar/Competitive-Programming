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
#define MAXN 1010

using namespace std;

const int W = 510;

int N;
ll S, c[MAXN], w[MAXN], best[MAXN];

int M = 0, comp[MAXN * MAXN];
unordered_map<int, ll> dp;

int main(){
    optimize;
    
    cin >> N >> S;

    for(int i = 0; i < N; i++){
        cin >> w[i] >> c[i];
        best[w[i]] = max(best[w[i]], c[i]);
    }

    //Melhor escolha com 1 item
    for(int i = 1; i < MAXN; i++){
        best[i] = max(best[i - 1], best[i]);
    }

    //Calculando coordenadas
    comp[M++] = S;

    int l = S, r = S;

    for(int i = 0; i < 35; i++){

        l = max(1, l / 2 - W);
        r = min(r - 1, r / 2 + W);

        for(int j = l; j <= r; j++){
            comp[M++] = j;
        }
    }

    //Ordenando coordenadas para compressao
    sort(comp, comp + M);
    M = unique(comp, comp + M) - comp;

    for(int i = 0; i < M; i++){
        
        ll &val = dp[comp[i]];
        
        val = best[min(MAXN - 1, comp[i])];

        int l = max(1, comp[i] / 2 - W), r = min(comp[i] - 1, comp[i] / 2 + W);
        
        for(int j = l; j <= r; j++){
            val = max(val, dp[j] + dp[comp[i] - j]);
        }
    }
    
    cout << dp[S] << endl;

    return 0;   
}