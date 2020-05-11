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
    
    int n;
    cin >> n;
    vector<pii> p(n);
    vector<bool> v(n, false);
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++){
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(all(p));
    for(int i = 0; i < n; i++){
        if(!v[i]){
            ans.emplace_back();
            ans.back().push_back(p[i].second + 1);
            v[i] = true;
            int j = p[i].second;
            while(!v[j]){
                ans.back().push_back(p[j].second + 1);
                v[j] = true;
                j = p[j].second;
            }
        }
    }

    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i].size() << " ";
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;   
}
