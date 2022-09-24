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

//Ax = B

int n, m;
vector<vector<bool>> A;
vector<bool> B, x;

bool gaussXor(){
    for(int i = 0; i < n; i++){
        
        for(int j = i; j < n; j++){
            if(A[j][i]){
                A[i].swap(A[j]);
                swap(B[i], B[j]);
                break;
            }
        }

        if(!A[i][i]) continue;

        for(int j = i + 1; j < n; j++){
            if(A[j][i]){
                for(int k = i; k < n; k++)
                    A[j][k] = (A[j][k] ^ A[i][k]);
                B[j] = B[j] ^ B[i];
            }
        }
    }

    for(int i = n - 1; i >= 0; i--){
        if(!A[i][i]){
            if(B[i]) 
                return false;
            else
                x[i] = true;
        }
        else{
            x[i] = B[i];
        }

        if(x[i]){
            for(int j = 0; j < i; j++){
                if(A[j][i])
                    B[j] = B[j] ^ x[i];
            }
        }
    }

    return true;
}

int main(){
    optimize;
    
    cin >> n >> m;

    A.assign(n, vector<bool>(n, false));
    B.assign(n, false);
    x.assign(n, false);

    vector<int> g(n, 0);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        A[a - 1][b - 1] = A[b - 1][a - 1] = true;
    
        g[a - 1]++, g[b - 1]++;
    }

    for(int i = 0; i < n; i++){
        if(g[i] % 2){
            B[i] = false;
            A[i][i] = true;
        }
        else{
            B[i] = true;
        }
    }

    cout << (gaussXor() ? "Y" : "N") << "\n";

    return 0;   
}