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

    int t, p[7] = {7, 27, 41, 49, 63, 78, 108};
    cin >> t;

    while(t--){
        int n, a, sum = 0;
        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> a;
            sum += p[a - 1];
        }

        if(sum >= 120)
            sum -= 50;
        else if(sum >= 89)
            sum -= 30;
        else if(sum >= 69)
            sum -= 15;

        cout << sum << "\n";
    }
    
    return 0;   
}
