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

#define MAXN 2009

int N, M;
vector<int> B;
vector<bitset<MAXN>> A;
bitset<MAXN> x;

bool gaussxor(){
    int cnt = 0, n = A.size(), m = MAXN;
    bitset<MAXN> vis; vis.set();
    for(int j = m - 1, i; j >= 0; j--){
        for(i = cnt; i < n; i++){
            if(A[i][j]) break;
        }
        if(i == n) continue;
        swap(A[i], A[cnt]); swap(B[i], B[cnt]);
        i = cnt++; vis[j] = 0;
        for(int k = 0; k < n; k++){
            if(i == k || !A[k][j]) continue;
            A[k] ^= A[i]; B[k] ^= B[i];
        }

        // for(int a = 0; a < N; a++){
        //     for(int b = 0; b < M; b++){
        //         cout << A[a][b] << " ";
        //     }
        //     cout << " = " << B[a] << "\n";
        // }
    }

    cout << "\n";

    x = vis;
    for(int i = 0; i < n; i++){
        int acum = 0;
        for(int j = 0; j < m; j++){
            if(!A[i][j]) continue;
            if(!vis[j]){
                vis[j] = 1;
                x[j] = acum^B[i];
            }
            acum ^= x[j];
        }
        if(acum != B[i]) return false;
    }
    return true;
}

int main(int argc, char **argv){
    //optimize;

    N = atoi(argv[1]);
    M = atoi(argv[2]);
    int T = atoi(argv[3]);

    srand(time(NULL));

    while(T--){
        A.resize(N);
        B.resize(N);

        for(int i = 0; i < N; i++)
            for(int j = 0; j < M; j++)
                A[i][j] = (int)(i == j);

        for(int i = 0; i < N; i++)
            B[i] = 1;


        // for(int i = 0; i < N; i++){
        //     for(int j = 0; j < M; j++){
        //         cout << A[i][j] << " ";
        //     }
        //     cout << " = " << B[i] << "\n";
        // }

        // cout << "\n";

        bool solvable = gaussxor();

        cout << (solvable? "YES" : "NO") << endl;
        if(solvable){
            for(int i = 0; i < M; i++)
                cout << x[i];
            cout << endl;
        }
    }
    return 0;   
}
