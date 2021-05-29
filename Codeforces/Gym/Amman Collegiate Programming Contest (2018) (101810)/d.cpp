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
        ll n, m, ans1, ans2;
        cin >> n >> m;

        ans1 = ((m + 2)/2) * (n/2) + ((m + 1)/2) * ((n + 1)/2);
        swap(n, m);
        ans2 = ((m + 2)/2) * (n/2) + ((m + 1)/2) * ((n + 1)/2);

        cout << min(ans1, ans2) << "\n"; 
    }

    return 0;   
}
