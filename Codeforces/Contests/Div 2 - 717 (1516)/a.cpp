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
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        
        for(int i = 0; i < n - 1 && k > 0; i++){
            if(a[i] <= k){
                k -= a[i];
                a[n - 1] += a[i];
                a[i] = 0;
            }
            else{
                a[i] -= k;
                a[n - 1] += k;
                k = 0;
            }
        }

        for(int i = 0; i < n; i++)
            cout << a[i] << " \n"[i==n-1];
    }
    
    return 0;   
}
