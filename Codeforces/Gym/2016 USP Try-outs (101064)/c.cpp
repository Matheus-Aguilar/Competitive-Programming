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

    int h, w, d = INF;
    cin >> h >> w;

    vector<int> w1(h), w2(h);

    for(int i = 0; i < h; i++)
        cin >> w1[i];

    for(int i = 0; i < h; i++)
        cin >> w2[i];

    for(int i = 0; i < h; i++){
        d = min(d, w - w2[i] - w1[i]);
    }

    cout << fixed << setprecision(9) << d / 2.0 << "\n";
    
    return 0;   
}
