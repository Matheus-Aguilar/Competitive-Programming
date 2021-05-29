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
        int even = 0, odd = 0;

        while (n--){
            int x;
            cin >> x;
            if(x & 1) odd++;
            else even++;
        }

        if(!odd) cout << "NO" << '\n';
        else if(!even && !(odd & 1)) cout << "NO" << '\n';
        else cout << "YES" << '\n'; 
    }

    return 0;   
}
