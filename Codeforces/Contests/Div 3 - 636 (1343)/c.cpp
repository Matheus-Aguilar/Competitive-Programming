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
        vector<ll> a(n);
        vector<ll> ans;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        ans.push_back(a[0]);
        for(int i = 1; i < n; i++){
            if(ans.back() * a[i] > 0){
                ans.back() = max(ans.back(), a[i]);
            }
            else{
                ans.push_back(a[i]);
            }
        }

        cout << accumulate(all(ans), 0LL) << "\n";
    }

    return 0;   
}
