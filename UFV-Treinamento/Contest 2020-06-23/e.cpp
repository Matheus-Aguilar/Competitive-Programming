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
    
    int a1, b1, a2, b2, a3, b3;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;

    if(a2 + a3 <= a1 && max(b2, b3) <= b1)
        cout << "YES" << "\n";
    else if(b2 + b3 <= b1 && max(a2, a3) <= a1)
        cout << "YES" << "\n";
    else if(a2 + b3 <= a1 && max(b2, a3) <= b1)
        cout << "YES" << "\n";
    else if(b2 + a3 <= a1 && max(a2, b3) <= b1)
        cout << "YES" << "\n";
    else if(a2 + a3 <= b1 && max(b2, b3) <= a1)
        cout << "YES" << "\n";
    else if(b2 + b3 <= a1 && max(a2, a3) <= b1)
        cout << "YES" << "\n";
    else if(a2 + b3 <= b1 && max(b2, a3) <= a1)
        cout << "YES" << "\n";
    else if(b2 + a3 <= b1 && max(a2, b3) <= a1)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";

    return 0;   
}
