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
#define MAXN 1100

using namespace std;

struct Show{
    int i, f, o, p;
    Show(int _i, int _f, int _o, int _p):i(_i), f(_f), o(_o), p(_p){}
    bool operator<(const Show &s){
        return i < s.i;
    }
};

int n, maxBit;
int dp[MAXN][MAXN];
bool ok[MAXN][MAXN];
int prox[MAXN];
vector<Show> s;

//i = bitmask, j = indice do show
int solve(int i, int j){
    //Ja foram todos os shows
    if(j == s.size()){
        if(i == maxBit) return 0; //Elemento Neutro (todos os palcos foram visitados)
        return -INF; //Caso invalido (faltaram palcos)
    }
    //Checa se é melhor ignorar o show ou pegar o show
    if(!ok[i][j]){ 
        dp[i][j] = max(solve(i, j + 1), solve((i | (1 << s[j].p)), prox[j]) + s[j].o);
        ok[i][j] = true;
    }
    return dp[i][j];
}

int main(){
    optimize;

    cin >> n;
    maxBit = ((1 << n) - 1);
    
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        while(m--){
            int ini, fim, horas;
            cin >> ini >> fim >> horas;
            s.emplace_back(ini, fim, horas, i);
        }
    }

    sort(all(s));

    for(int i = 0; i < s.size(); i++)
        prox[i] = lower_bound(all(s), Show(s[i].f, 0, 0, 0)) - s.begin();
    
    int res = solve(0, 0);

    cout << (res < 0 ? -1 : res) << "\n";

    return 0;   
}
