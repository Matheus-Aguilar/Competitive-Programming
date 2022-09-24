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

int N, M;
map<vector<ll>, bool> m;
vector<ll> v;
vector<ll> w;

bool solve(vector<ll> &a, int n){
    vector<ll> b;
    m[a] = true;
    if(n == w.size()){
        b = a;
        reverse(all(b));
        return a == w || b == w;
    }
    for(int k = 0; k < n - 1; k++){
        
        b.resize(max(k + 1, n - k - 1));
        
        if(b.size() < w.size()) continue;

        if(k + 1 > n - k - 1){
            for(int i = 0; i < 2 * k + 2 - n; i++){
                b[i] = a[i];
            }
            for(int i = 2 * k + 2 - n, j = n - 1; i < j; i++, j--){
                b[i] = a[i] + a[j];
            }
        }
        else{
            for(int i = 0; i < n - 2 * k - 2; i++){
                b[i] = a[n - i - 1];
            }
            for(int i = n - 2 * k - 2, j = 0; i < b.size(); i++, j++){
                b[i] = a[n - i - 1] + a[j];
            }
        }

        if(m.find(b) == m.end()){
            if(solve(b, b.size()))
                return true;
        }
    }
    b = a;
    reverse(all(b));
    if(m.find(b) == m.end()){
        if(solve(b, b.size()))
            return true;
    }
    return false;
}

int main(){
    optimize;

    while(cin >> N){
        m.clear();
        v.resize(N);
        for(int i = 0; i < N; i++)
            cin >> v[i];
        cin >> M;
        w.resize(M);
        for(int i = 0; i < M; i++)
            cin >> w[i];
        cout << (solve(v, N) ? "S" : "N") << "\n";
    }
    return 0;   
}
