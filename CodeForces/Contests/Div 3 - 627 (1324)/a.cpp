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

        int odd = 0, even = 0;

        while(n--){
            int a;
            cin >> a;
            if(a & 1) odd++;
            else even++;
        }

        if(even && odd) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }
    
    return 0;   
}
