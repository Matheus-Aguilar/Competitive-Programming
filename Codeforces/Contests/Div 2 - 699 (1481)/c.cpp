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

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(n), c(m), sol(m, -1);
        vector<vector<int>> paint(n + 1);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        for(int i = 0; i < n; i++){
            cin >> b[i];
            if(b[i] != a[i]) paint[b[i]].push_back(i);
        }

        for(int i = 0; i < m; i++){
            cin >> c[i];
        }

        bool ok = true;

        for(int i = 0; i < m - 1; i++){
            if(!paint[c[i]].empty()){
                sol[i] = paint[c[i]].back();
                paint[c[i]].pop_back();
                a[sol[i]] = c[i];
            }
        }

        if(!paint[c[m - 1]].empty()){
            sol[m - 1] = paint[c[m - 1]].back();
            paint[c[m - 1]].pop_back();
            a[sol[m - 1]] = c[m - 1];
        }
        else{
            ok = false;

            for(int i = 0; i < n && !ok; i++){
                if(a[i] == c[m - 1]){
                    sol[m - 1] = i;
                    ok = true;
                }
            }
        }

        if(ok){
            for(int i = 0; i < m - 1; i++){
                if(sol[i] == -1){
                    sol[i] = sol[m - 1];
                }
            }
        }

        for(int i = 1; i <= n && ok; i++){
            if(!paint[i].empty()){
                ok = false;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";

        if(ok){
            for(int i = 0; i < m; i++)
                cout << sol[i] + 1 << " \n"[i==m-1];
        
            // for(int i = 0; i < m; i++)
            //     a[sol[i]] = c[i];
            
            //assert(a == b);
        }
    }
    
    return 0;   
}
