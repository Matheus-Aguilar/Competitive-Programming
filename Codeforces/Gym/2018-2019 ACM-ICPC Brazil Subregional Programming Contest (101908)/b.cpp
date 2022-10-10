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
#define MAXN 110

using namespace std;

int grundy[MAXN][MAXN];

int mex(int l, int c){
    bool states[4 * MAXN];
    ms(states, 0);
    for(int i = l - 1; i >= 0; i--)
        if(grundy[i][c] != INF)
            states[grundy[i][c]] = true;
    for(int i = c - 1; i >= 0; i--)
        if(grundy[l][i] != INF)
            states[grundy[l][i]] = true;
    for(int i = l - 1, j = c - 1; i >= 0 && j >= 0; i--, j--)
        if(grundy[i][j] != INF)
            states[grundy[i][j]] = true;
    for(int i = 0; i < 4 * MAXN; i++)
        if(!states[i])
            return i;
}

void precalc(){
    ms(grundy, INF);
    for(int i = 1; i < MAXN; i++){
        for(int j = 1; j < MAXN; j++){
            if(i == j) continue;
            grundy[i][j] = mex(i, j);
        }
    }
}

int main(){
    optimize;

    precalc();

    int n, sum = 0;
    cin >> n;

    while(n--){
        int l, c;
        cin >> l >> c;

        if(grundy[l][c] == INF){
            cout << "Y" << "\n";
            return 0;
        }
        else{
            sum ^= grundy[l][c];
        }
    }

    cout << (sum ? "Y" : "N") << "\n";

    return 0;   
}
