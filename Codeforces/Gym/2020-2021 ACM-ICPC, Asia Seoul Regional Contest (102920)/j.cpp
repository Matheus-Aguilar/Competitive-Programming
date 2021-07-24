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

int n;
vector<vector<int>> A, x;
vector<vector<int>> ans;

void print(vector<int> &a){
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << "\n";
}

bool solve(){

    for(int i = 0; i < n; i++){
        
        for(int j = i; j < n; j++){
            if(A[j][i]){
                swap(A[i], A[j]);
                swap(x[i], x[j]);
                break;
            }
        }

        if(!A[i][i]) continue;

        for(int j = i + 1; j < n; j++){
            if(A[j][i]){
                for(int k = 0; k < n; k++){
                    A[j][k] ^= A[i][k];
                    x[j][k] ^= x[i][k];
                }
            }
        }
    }

    for(int i = n - 1; i >= 0; i--){
        
        if(!A[i][i]) return false;

        for(int j = i - 1; j >= 0; j--){
            if(A[j][i]){
                for(int k = 0; k < n; k++){
                    A[j][k] ^= A[i][k];
                    x[j][k] ^= x[i][k];
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(x[i][j]){
                ans[j].push_back(i + 1);
            }
        }
    }

    return true;
}

int main(){
    optimize;
    
    cin >> n;

    A.assign(n, vector<int>(n));
    x.assign(n, vector<int>(n, false));
    ans.resize(n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> A[j][i];
    
    for(int i = 0; i < n; i++)
        x[i][i] = true;

    if(solve()){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < ans[i].size(); j++){
                cout << ans[i][j] << " \n"[j+1==ans[i].size()];
            }
        }
    }
    else{
        cout << -1 << "\n";
    }

    return 0;   
}
