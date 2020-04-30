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
    //optimize;
    
    int n;

    cin >> n;

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) c[i] = a[i] - b[i];

    sort(all(c), greater<int>());

    ll ans = 0;

    int p1 = 0, p2 = n - 1;

    while(p1 != p2){
        if(c[p1] + c[p2]  > 0){
            ans += p2 - p1;
            p1++;
        }
        else{
            p2--;
        }
    }

    cout << ans << "\n";
    return 0;   
}
