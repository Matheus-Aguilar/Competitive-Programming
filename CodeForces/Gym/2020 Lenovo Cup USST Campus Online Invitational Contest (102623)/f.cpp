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
#define MAXN 100100

using namespace std;

int main(){
    optimize;
    
    int k, n;
    cin >> k;

    cout << 4 * k << " " << 2 * k << "\n";

    n = 2;
    for(int i = 0; i < k; i++){
        cout << n << " ";
        n *= 2;
    }

    n = 3;
    for(int i = 0; i < k; i++){
        cout << n << " ";
        n *= 3;
    }

    n = 15;
    for(int i = 0; i < k; i++){
        cout << n << " ";
        n *= 15;
    }

    n = 10;
    for(int i = 0; i < k; i++){
        cout << n << " ";
        n *= 10;
    }

    cout << "\n";

    for(int i = 1; i <= 2 * k; i++)
        cout << i << " ";
    for(int i = 1; i <= 2 * k; i++)
        cout << i << " ";

    cout << "\n";

    return 0;
}
