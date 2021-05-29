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

// |f(n)    | | 17 10  5  2| |f(n - 1)|
// |f(n - 1)| |  1  0  0  0| |f(n - 2)|
// |f(n - 2)| |  0  1  0  0| |f(n - 3)|
// |f(n - 3)| |  0  0  1  0| |f(n - 4)|

// |f(n)    | | 17 10  5  2| ^ (n - 4) |f(4)|
// |f(n - 1)| |  1  0  0  0|           |f(3)|
// |f(n - 2)| |  0  1  0  0|           |f(2)|
// |f(n - 3)| |  0  0  1  0|           |f(1)|


//bases: f(1) = 1, f(2) = 17 * f(1), f(3) = 10 * f(1) + 17 * f(2), f(4) = 5 * f(1) + 10 * f(2) + 17 * f(3) 

const int dim = 4; //dimension of the matrix
typedef ll ntype; //type of numbers inside the matrix
ll p = 1000000007;

void print(ntype m[dim][dim]){
    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            cout << m[i][j] << " \n"[j==dim-1];
}

void mult(ntype a[dim][dim], ntype b[dim][dim]){
    
    ntype c[dim][dim];
    ms(c, 0);
    
    for(int i = 0; i < dim; i++)
        for(int j = 0; j < dim; j++)
            for(int k = 0; k < dim; k++)
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) mod) mod;  
    
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

ntype calc(ntype m[dim][dim], ntype base[dim]){
    
    ntype sum = 0;

    for(int i = 0, j = 3; j >= 0; i++, j--)
        sum = (sum + (m[0][i] * base[j]) mod) mod;

    return sum mod;
}

ntype solve(ll n){
    
    if(n < 0)
        return 0;

    //base cases of the recurrence, in crescent order
    ntype base[dim];

    base[0] = 1;
    base[1] = 16 * base[0];
    base[2] = 9 * base[0] + 16 * base[1];
    base[3] = 4 * base[0] + 9 * base[1] + 16 * base[2];
    
    if(n < dim)
        return base[n];
    
    //Transformation matrix
    ntype m[dim][dim] = {
        {16, 9, 4, 1},
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0}
    };
    
    fastExpo(m, n - dim + 1);

    //print(m);

    return calc(m, base);
}

int main(){
    optimize;

    ll n, v[5], ans = 0;
    cin >> n;

    v[0] = solve(n/10);
    v[1] = solve(n/10 - 1);
    v[2] = solve(n/10 - 2);
    v[3] = solve(n/10 - 3);
    v[4] = solve(n/10 - 4);
    
    if((n % 10) >= 5)
        v[4] = 0;

    for(int i = 0; i < 5; i++)
        ans = (ans + v[i]) mod;

    cout << ans << "\n";

    return 0;   
}
