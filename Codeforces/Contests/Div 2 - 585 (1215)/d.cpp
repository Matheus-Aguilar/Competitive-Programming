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
    
    int n, l = 0, r = 0, d =0;
    cin >> n;

    string s;
    cin >> s;

    for(int i = 0; i < n/2; i++){
        if(s[i] == '?')
            l += 9;
        else
            d += (int)(s[i] - '0');
    }
    for(int i = n/2; i < n; i++){
        if(s[i] == '?')
            r -= 9;
        else
            d -= (int)(s[i] - '0');
    }

    if((d + l) - (l - r)/2 < 0 || (d + r) + (l - r)/2 > 0)
        cout << "Monocarp" << "\n";
    else
        cout << "Bicarp" << "\n";

    return 0;   
}
