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

typedef tuple<int, int, int, int, int> tuple5;

int n, m, d;
vector<tuple5> states;

double dp[101][500][500];
bool ok[101][500][500];

void precalc(){
    for(int i = 0; i <= 6; i++){
        for(int j = i; j <= 6; j++){
            for(int k = j; k <= 6; k++){
                for(int u = k; u <= 6; u++){
                    for(int v = u; v <= 6; v++){
                        states.emplace_back(i, j, k, u, v);
                    }
                }
            }
        }
    }
}

int get(tuple5 t){
    return lower_bound(all(states), t) - states.begin();
}

void print(vector<int> &a){
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << ", ";
}

double solve(vector<int> a, vector<int> b, int d){
    
    if(all_of(all(b), [](int x){ return x == 0; })){
        return 1.0;
    }

    if(d == 0){
        return 0.0;
    }

    sort(all(a));
    sort(all(b));

    int i = get(tuple5(a[0], a[1], a[2], a[3], a[4]));
    int j = get(tuple5(b[0], b[1], b[2], b[3], b[4]));

    if(!ok[d][i][j]){

        dp[d][i][j] = 0.0;
        int cont = 0;

        for(int k = 0; k < 5; k++){
            if(a[k] != 0){

                a[k]--;

                dp[d][i][j] += solve(a, b, d - 1); 
                cont++;

                a[k]++;
            }
        }

        for(int k = 0; k < 5; k++){
            if(b[k] != 0){

                b[k]--;

                dp[d][i][j] += solve(a, b, d - 1); 
                cont++;

                b[k]++;
            }
        }

        dp[d][i][j] /= cont;
        ok[d][i][j] = true;
    }

    return dp[d][i][j];
}

int main(){
    optimize;

    precalc();

    cin >> n >> m >> d;

    vector<int> a(5, 0), b(5, 0);

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int i = 0; i < m; i++)
        cin >> b[i];
    
    cout << fixed << setprecision(9) << solve(a, b, d) << "\n";

    return 0;   
}
