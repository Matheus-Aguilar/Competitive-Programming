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
        vector<int> a(n);
        vector<int> c(2049, 0);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            c[a[i]]++;
        }
        int ans = -1;
        for(int i = 1; i <= 2048 && ans == -1; i++){
            ans = i;
            for(int j = 0; j < n && ans != -1; j++){
                if(c[a[j]] != c[a[j] ^ i])
                    ans = -1;
            }
        }
        cout << ans << "\n";
    }

    return 0;   
}
