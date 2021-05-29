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
        int n;
        cin >> n;
        vector<int> b(n);
        vector<int> res(n);
        vector<int> ans(2 * n);
        
        int k = 0;

        for(int i = 0; i < n; i++){
            cin >> b[i];
            ans[2 * i] = b[i];
        }

        for(int i = 1; i <= 2 * n; i++){
            if(find(b.begin(), b.end(), i) == b.end()){
                res[k++] = i;
            }
        }

        sort(b.begin(), b.end(), greater<int>());
        sort(res.begin(), res.end(), greater<int>());

        bool ok = true;

        for(int i = 0; i < n; i++){
            if(b[i] > res[i]){
                cout << -1 << "\n";
                ok = false;
                break;
            }

            int pos = (int)(find(ans.begin(), ans.end(), b[i]) - ans.begin());

            ans[pos + 1] = res[i];
        }

        if(ok){
            for(int i = 0; i < 2*n; i += 2){
                for(int j = i + 2; j < 2*n; j += 2){
                    if(ans[i] < ans[j + 1] && ans[j] < ans[i + 1] && ans[i + 1] > ans[j + 1])
                        swap(ans[i + 1], ans[j + 1]);
                }
            }
            for(int i = 0; i < 2 * n; i++)
                cout << ans[i] << " ";
            cout << "\n";
        }
    }
    
    return 0;   
}
