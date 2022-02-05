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
#define MAXN 1000100

using namespace std;

int n, fc = 0, pos[MAXN];
ll a[MAXN], f[MAXN];

bool v[MAXN];

void precalc(){

    f[0] = 1;
    f[1] = 1;

    fc = 2;

    while(f[fc - 1] <= 1000000000LL){
        f[fc] = f[fc - 1] + f[fc - 2];
        fc++;
    }

    fc--;
}

int main(){
    optimize;

    precalc();
    
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        v[a[i]] = true;
        pos[a[i]] = i;
    }

    bool ok = false;
    int x, y;

    for(int i = 0; i < n && !ok; i++){
        for(int j = 0; j < fc - 2 && !ok; j++){
            if((f[i + 1] * a[i] - 1) % f[i] == 0){
                
                ll b = (f[i + 1] * a[i] - 1) / f[i];

                if(v[b] && pos[b] != i){
                    if(f[i] * b - f[i + 1] * a[i] <= 0){
                        ok = true;
                        x = i;
                        y = pos[b];

                        cout << f[i] << " " << f[i + 1] << " " << f[i + 2] << " " << "AQUI1\n";
                    }
                }
            }
        }
    }

    for(int i = 0; i < n && !ok; i++){
        for(int j = 0; j < fc - 2 && !ok; j++){
            if((f[i + 1] * a[i] + 1) % f[i] == 0){
                
                ll b = (f[i + 1] * a[i] + 1) / f[i];

                if(v[b] && pos[b] != i){
                    if(f[i + 2] * a[i] - f[i + 1] * b <= 0){
                        ok = true;
                        x = i;
                        y = pos[b];


                        cout << "AQUI2\n";
                    }
                }
            }
        }
    }

    if(!ok)
        cout << "impossible" << "\n";
    else
        cout << x + 1 << " " << y + 1 << "\n";

    return 0;   
}
