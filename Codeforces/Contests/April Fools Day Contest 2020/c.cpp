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

    bool b1 = (n & (1 << 5));
    bool b2 = (n & (1 << 4));
    bool b3 = (n & (1 << 3));
    bool b4 = (n & (1 << 2));
    bool b5 = (n & (1 << 1));
    bool b6 = (n & (1 << 0));

    swap(b2, b6);
    swap(b3, b4);

    cout << ((int)b1 * 32) + ((int)b2 * 16) + ((int)b3 * 8) + ((int)b4 * 4) + ((int)b5 * 2) + ((int)b6 * 1) << "\n";



    return 0;   
}
