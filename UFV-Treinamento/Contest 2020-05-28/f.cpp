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
        
        ll sum, best = -INFLL, now = 0;

        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        sum = accumulate(all(a), 0LL);
        for(int i = 0; i < n - 1; i++){
            now += a[i];
            best = max(best, now);
            if(now < 0)
                now = 0;
        }

        now = 0;

        for(int i = 1; i < n; i++){
            now += a[i];
            best = max(best, now);
            if(now < 0)
                now = 0;
        }

        cout << (sum > best? "YES" : "NO") << "\n";
    }
    
    return 0;   
}
