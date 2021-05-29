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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        set<int> s;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s.insert(a[i]);
        }
        if(k < s.size())
            cout << -1 << "\n";
        else{
            vector<int> ans;
            for(auto i:s)
                ans.push_back(i);
            while(ans.size() < k) ans.push_back(1);
            cout << n * k << "\n";
            for(int i = 0; i < n; i++)
                for(int j = 0; j < k; j++)
                    cout << ans[j] << " ";
            cout << "\n";
        }
    }
    
    return 0;   
}
