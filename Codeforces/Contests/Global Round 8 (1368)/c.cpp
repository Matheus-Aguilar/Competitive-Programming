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

    vector<pii> ans;

    ans.push_back(pii(1, 1));

    for(int i = 2; i <= n + 2; i++){
        ans.push_back(pii(i, i));
        ans.push_back(pii(i - 1, i));
        ans.push_back(pii(i, i - 1));
    }

    cout << ans.size() << "\n";
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << "\n";

    return 0;   
}
