#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;
    
    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;
        int a[n];
        int p[m];

        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> p[i];

        sort(p, p + m);

        for(int k = 0; k < m; k++){
            for(int i = 0; i < m; i++){
                if(p[i] != n && a[p[i] - 1] > a[p[i]])
                        swap(a[p[i] - 1], a[p[i]]);
                // for(auto p0:a) cout << p0 << " ";
                // cout << "\n";
            }
        }

        bool ans = true;

        for(int i = 0; i < n - 1; i++){
            if(a[i] > a[i + 1]){
                ans = false;
            }
        }

        cout << (ans ? "YES" : "NO") << "\n";
    }

    return 0;   
}
