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

const int d = 2, p = 1000;
typedef int ntype;

void mult(ntype a[d][d], ntype b[d][d]){

    ntype c[d][d];
    
    ms(c, 0);

    for(int i = 0; i < d; i++)
        for(int j = 0; j < d; j++)
            for(int k = 0; k < d; k++)
                c[i][j] = (c[i][j] + (a[i][k] % p * b[k][j] % p) % p) % p;
    
    for(int i = 0; i < d; i++)
        for(int j = 0; j < d; j++)
            a[i][j] = c[i][j];
}

void fastExpo(ntype x[d][d], string &y){
    ntype r[d][d];

    for(int i = 0; i < d; i++)
        for(int j = 0; j < d; j++)
            r[i][j] = (i == j);

    for(int i = y.size() - 1; i >= 0; i--){
        if(y[i] == '1')
            mult(r, x);  
        mult(x, x);
    }

    for(int i = 0; i < d; i++)
        for(int j = 0; j < d; j++)
            x[i][j] = r[i][j];
}

int solve(string &s){
    if(s == "0")
        return 0;
    if(s == "1")
        return 1;
    
    ntype m[d][d] = {
        {1, 1},
        {1, 0}
    };

    /*s -= 1*/

    int i = 0;
    
    for(i = (int)s.size() - 1; i >= 0 && s[i] != '1'; i--)
        s[i] = '1';
    
    s[i] = '0';

    /*-----*/

    fastExpo(m, s);

    return m[0][0];
}

int main(){
    optimize;
    
    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;
        cout << setfill('0') << setw(3) << solve(s) << "\n";
    }

    return 0;   
}
