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
#define MAXN 1000010

using namespace std;

int rep[MAXN];
int a[MAXN];

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){

        ms(rep, -1);

        int n;
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);

        ll ans = 0;
        
        for(int i = 0; i < n; i++){
            if(rep[a[i]] == -1)
                for(int j = a[i]; j <= a[n - 1]; j += a[i])
                    if(rep[j] == -1)
                        rep[j] = a[i];
            ans += rep[a[i]];
        }

        cout << ans << "\n";
    }
    
    return 0;   
}
