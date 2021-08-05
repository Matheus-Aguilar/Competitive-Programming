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

    int n;
    cin >> n;

    ll sum = 0;
    vector<int> a(n);
    
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++){
        sum += (i % 2 ? -a[i] : a[i]);
    }

    int q;
    cin >> q;

    while(q--){
        int l, r, v;
        cin >> l >> r >> v;

        if((r - l + 1) % 2 != 0){
            if(l % 2 != 0){
                sum += v;
            }
            else{
                sum -= v;
            }
        }

        cout << (n % 2 ? sum : -sum) << "\n";
    }

    return 0;   
}
