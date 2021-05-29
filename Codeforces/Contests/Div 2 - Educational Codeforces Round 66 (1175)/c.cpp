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
#define MAXN 200200

using namespace std;

int n, k, a[MAXN];

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        
        cin >> n >> k;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int x = 0, fx = INF;

        for(int i = 0; i < n - k; i++){
            if(fx > (a[i + k] - a[i] + 1) / 2){
                fx = (a[i + k] - a[i] + 1) / 2;
                x = fx + a[i];
            }
        }
        
        cout << x << "\n";
    }
    
    return 0;   
}
