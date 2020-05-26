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
        int n, ans = 1, now = 0;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(all(a));
        for(int i = 0; i < n; i++){
            if(ans + now >= a[i]){
                ans += now + 1;
                now = 0;
            }
            else{
                now++;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;   
}
