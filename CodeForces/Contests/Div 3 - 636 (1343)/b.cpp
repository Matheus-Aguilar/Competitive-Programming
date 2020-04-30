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

        n /= 2; 

        if(n % 2 != 0){
            cout << "NO" << "\n";
        }
        else{
            cout << "YES" << "\n";
            for(int i = 1; i <= n - 1; i++)
                cout << 2 * i << " ";
            cout << 3 * n << " ";
            for(int i = 1; i <= n; i++)
                cout << 2 * i + 1 << " ";
            cout << "\n";
        }
    }
    
    return 0;   
}
