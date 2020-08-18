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

    ll p;
    cin >> p;

    vector<int> ans(p, -1);
    for(ll i = 0; i < p; i++)
        ans[(i * i) % p] = i;
    for(int i = 0; i < p; i++)
        cout << ans[i] << " \n"[i==p-1];
    
    return 0;   
}
