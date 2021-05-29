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

const int K = 150;

int main(){
    optimize;

    double c, l = 0.0, r = INFLL, m, x;
    cin >> c;
    
    for(int i = 0; i < K; i++){
        
        m = l + (r - l)/2;

        if(m * m * m * m + m <= c)
            l = m;
        else
            r = m;
    }

    x = m * m;    

    cout << fixed << setprecision(9) << x << "\n";

    return 0;   
}
