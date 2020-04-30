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
        int n;
        cin >> n;

        vector<vector<int>> prefix(201, vector<int>(n, 0));
        vector<vector<int>> pos(201);
        vector<int> v(n);
        vector<int> ptr(201);

        for(int i = 0; i < n; i++){
            cin >> v[i];
            if(i > 0){
                for(int j = 1; j <= 200; j++){
                    prefix[j][i] = prefix[j][i - 1];
                }
            }
            prefix[v[i]][i]++;
            ptr[v[i]] = pos[v[i]].size(); 
            pos[v[i]].push_back(i);
        }

        int best = -1;
        for(int i = 1; i <= 200; i++) 
            best = max(best, prefix[i][n - 1]);

        for(int i = 0; i < n; i++){

            if(i >= pos[v[i]][ptr[v[i]]]) continue;

            int y = -INF;
            int l = i;
            int r = pos[v[i]][ptr[v[i]]] - 1;
            
            for(int j = 1; j <= 200; j++)
                y = max(y, prefix[j][r] - prefix[j][l]);

            int x = pos[v[i]].size() - ptr[v[i]];
            ptr[v[i]]--;
            best = max(best, 2 * x + y);
        }
        cout << best << '\n';
    }
    
    return 0;   
}
