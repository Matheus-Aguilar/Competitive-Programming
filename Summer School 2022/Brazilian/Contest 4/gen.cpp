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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
    optimize;
    
    cout << 15 << "\n";

    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 15; j++){
            cout << (char)('A' + rng() % 26);
        }
        cout << "\n";
    }

    return 0;   
}
