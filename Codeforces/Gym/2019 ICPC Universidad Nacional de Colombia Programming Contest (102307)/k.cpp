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
#define MAXN 30

using namespace std;

//  n % 3 = 0 -> 2n/3 imp e n/3 par
//  n % 3 = 0 -> 2n/3 + 1 imp e n/3 par
//  n % 3 = 0 -> 2n/3 + 2 imp e n/3 par

int main(int agrc, char **argv){
    optimize;
    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;


        if(n <= 2)
            cout << 0 << "\n";
        else if(n % 3 == 0)
            cout << 2 * (n/3) << "\n";
        else if(n % 3 == 1)
            cout << 2 * (n/3) + 1 << "\n";
        else if(n % 3 == 2)
            cout << 2 * (n/3) + 1 << "\n";
    }

    return 0;   
}
