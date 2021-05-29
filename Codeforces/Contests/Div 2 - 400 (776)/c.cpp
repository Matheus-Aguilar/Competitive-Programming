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
#define MAXN 100100
#define MAXM 50

using namespace std;

const int m[11] = {0, 2, 50, 35, 25, 20, 20, 20, 20, 20, 20}; 

int n, k;
ll sum = 0LL, acu = 0LL, ans = 0LL, a[MAXN], p[MAXM], suffix;
map<ll, ll> prefix;

int main(){
    optimize;

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    p[0] = 1LL;
    for(int i = 1; i < m[abs(k)]; i++)
        p[i] = p[i - 1] * k;


    prefix[0LL] = 1LL;
    for(int i = 0; i < n; i++){
        acu += a[i];
        prefix[acu]++;
    }

    for(int i = 0; i < m[abs(k)]; i++)
        ans += prefix[sum - p[i]];

    suffix = 0;
    for(int i = n - 1; i >= 0; i--){
        prefix[acu]--;
        acu -= a[i];
        suffix += a[i];

        for(int j = 0; j < m[abs(k)]; j++)
            ans += prefix[sum - suffix - p[j]];
    }

    if(k == 1) ans /= 2LL;

    cout << ans << "\n";

    return 0;   
}
