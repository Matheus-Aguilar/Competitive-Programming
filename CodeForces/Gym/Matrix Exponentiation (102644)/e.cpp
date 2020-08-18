#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 4294967296LL
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

const int dim = 128; //dimension of the matrix
typedef ll ntype; //type of numbers inside the matrix

void mult(ntype a[dim][dim], ntype b[dim][dim]){
    
    ntype c[dim][dim];
    ms(c, 0);
    
    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            for(int k = 0; k < dim; k++)
                c[i][j] = (c[i][j] + ((a[i][k] * b[k][j] + 4294967296LL) mod) + 4294967296LL) mod; 
    
    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            a[i][j] = c[i][j];
}

void fastExpo(ntype x[dim][dim], ll y){

    ntype r[dim][dim];

    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            r[i][j] = (i == j);
    
    while(y > 0){
        if(y & 1)
            mult(r, x);
        y >>= 1;
        mult(x, x);
    }

    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            x[i][j] = r[i][j];
}

ntype calc(ntype m[dim][dim], ntype f[dim]){
    
    ntype res[dim];
    ll sum = 0;

    ms(res, 0);
    for(int i = 0; i < dim/2; i++)
        for(int j = 0; j < dim; j++)
            res[i] = (res[i] + ((m[i][j] * f[j] + 4294967296LL) mod) + 4294967296LL) mod;

    for(int i = 0; i < dim/2; i++)
        sum = (sum + res[i]) mod;
    
    return sum;
}

ntype calc(ll k){
    
    if(k == 0)
        return 1;
    if(k == 1)
        return 3;

    //base cases of the recurrence, in crescent order
    ntype base[dim];

    ms(base, 0);
    base[0] = 1;
    base[8 * 2 + 1] = 1;
    base[8 * 1 + 2] = 1;
    base[8 * 8] = 1;


    //Transformation matrix
    ntype m[dim][dim];

    int pos[][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    ms(m, 0);
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            for(int k = 0; k < 8; k++){
                if(i + pos[k][0] >= 0 && i + pos[k][0] < 8 && j + pos[k][1] >= 0 && j + pos[k][1] < 8){
                    m[i * 8 + j][(i + pos[k][0]) * 8 + j + pos[k][1]] = 1;
                    m[i * 8 + j][(i + 8 + pos[k][0]) * 8 + j + pos[k][1]] = -1;
                }
                m[i * 8 + j][i * 8 + j] = 1;
                m[(i + 8) * 8 + j][i * 8 + j] = 1;
            }
        }
    }

    fastExpo(m, k - 1);

    return calc(m, base);
}

int main(){
    optimize;

    ll k;
    cin >> k;
    
    cout << calc(k) << "\n";

    return 0;   
}
