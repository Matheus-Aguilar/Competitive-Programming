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
    
    int n, up = 0, down = 0;
    bool dif = false;
    cin >> n;
    while(n--){
        int u, d;
        cin >> u >> d;
        up += u;
        down += d;
        if(u % 2 != d % 2)
            dif = true;
    }

    if(up % 2 == 0 && down % 2 == 0)
        cout << 0 << "\n";
    else if(up % 2 != 0 && down % 2 != 0){
        if(dif)
            cout << 1 << "\n";
        else
            cout << -1 << "\n";
    }
    else{
        cout << -1 << "\n";
    }

    return 0;   
}
