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
    
    int n, m;
    cin >> n >> m;

    while(m--){
        ll num, k, ans = 0;
        cin >> num >> k;

        k %= n;

        while(k--){
            bool bit = (num & (1LL << (n - 1)));
            num <<= 1;
            num |= bit;
            num ^= (num & (1LL << n));
        }

        cout << num << "\n";
    }

    return 0;   
}
