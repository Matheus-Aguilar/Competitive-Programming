#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;

        int ans;

        if(a == b) ans = 0;
        else if(a < b && (b - a) % 2 == 0) ans = 2;
        else if(a > b && (a - b) % 2 !=  0) ans = 2;
        else ans = 1;

        cout << ans << "\n";
    }

    return 0;   
}
