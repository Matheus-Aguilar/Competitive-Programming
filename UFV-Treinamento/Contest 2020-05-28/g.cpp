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

    int n, h = 0, p = 1;
    cin >> n;

    while(p <= n){
        p *= 10;
        h = max(h, (n % p)/(p/10));
    }

    cout << h << "\n";
    for(int i = 0; i < h; i++){
        bool first = true;
        for(int j = p; j > 1; j /= 10){
            if((n % j)/(j/10)){
                cout << 1;
                n -= (j/10);
                first = false;
            }
            else if(!first)
                cout << 0;
        }
        cout << " ";
    }

    cout << "\n";
    
    return 0;   
}
