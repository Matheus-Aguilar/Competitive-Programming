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

const int dim = 2; //dimension of the matrix
typedef long double ntype; //type of numbers inside the matrix
long double p;

void mult(ntype a[dim][dim], ntype b[dim][dim]){
    
    ntype c[dim][dim];
    ms(c, 0);
    
    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            for(int k = 0; k < dim; k++)
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j])); 
    
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
    ntype sum = 0;
    for(int i = 0; i < dim; i++)
        sum = (sum + (m[0][i] * f[dim - i - 1]));
    return sum;
}

ntype calc(ll n){
    
    //base cases of the recurrence, in crescent order
    ntype base[dim] = {1, 1};
    
    if(n < dim - 1)
        return base[n];
    
    //Transformation matrix
    ntype m[dim][dim] = {{1 - 2 * p, p}, {0, 1}};
    
    fastExpo(m, n - dim + 2);

    return calc(m, base);
}

int main(){
    optimize;

    ll n;
    cin >> n >> p;    
    cout << fixed << setprecision(12) << calc(n) << "\n";

    return 0;   
}
