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
        int x, n;
        cin >> x >> n;

        vector<int> v(n, x/n);

        if(v[0] == 0){
            cout << -1 << "\n";
        }
        else{
            for(int i = n - 1; i > n - x % n - 1; i--)
                v[i]++;
            for(int i = 0; i < n; i++)
                cout << v[i] << " \n"[i==n-1];
        }
    }
    
    return 0;   
}
