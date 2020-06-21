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
    
    int n, cd = 0, cx = 0;
    cin >> n;

    while(n--){
        int d, x;
        cin >> d >> x;

        if((d + 1) % 5 == x || (d + 2) % 5 == x)
            cd++;
        else
            cx++;
    }

    cout << (cd > cx ? "dario" : "xerxes") << "\n";

    return 0;   
}
