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
#define MAXN 220

using namespace std;

int n, m;
double mat[MAXN][MAXN];

void copyMat(double src[MAXN][MAXN], double dest[MAXN][MAXN]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dest[i][j] = src[i][j];
        }
    }
}

void mult(double a[MAXN][MAXN], double b[MAXN][MAXN]){
    double c[MAXN][MAXN];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    copyMat(c, a);
}

void fastExpo(double x[MAXN][MAXN], int y){
    double r[MAXN][MAXN];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            r[i][j] = (i == j);
        }
    }

    while(y > 0){
        if(y & 1)
            mult(r, x);
        mult(x, x);
        y >>= 1;
    }

    copyMat(r, x);
}

int main(){
    optimize;
    
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[j][i];
        }
    }

    fastExpo(mat, m);

    for(int i = 0; i < n; i++){
        cout << fixed << setprecision(12) << mat[i][0] << "\n";
    }

    return 0;   
}
