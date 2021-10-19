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

int n, a[100];

int solve(){
    int last = a[0], cont = 1;
    bool up = true;

    for(int i = 1; i < n; i++){
        if(up){
            if(a[i] > last){
                cont++;
                up = false;
            }
        }
        else{
            if(a[i] < last){
                cont++;
                up = true;
            }
        }
        last = a[i];
    }

    return cont;
}

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int ans = solve();

    for(int i = 0; i < n; i++)
        a[i] *= -1;
    
    ans = max(ans, solve());

    cout << ans << "\n";
    
    return 0;   
}
