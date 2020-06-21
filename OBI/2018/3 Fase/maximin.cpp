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

    int n, l, r, best = 0;
    cin >> n >> l >> r;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];

    sort(all(v));

    int minL = INF, minR = INF;

    for(int i = 0; i < n; i++)
        minL = min(minL, abs(v[i] - l));
    for(int i = 0; i < n; i++)
        minR = min(minR, abs(v[i] - r));
    
    best = max(minL, minR);

    for(int i = 0; i < n - 1; i++){
        int val = v[i] + (v[i + 1] - v[i])/2;
        if(l <= val && val <= r)
            best = max(best, val - v[i]);
    }

    cout << best << "\n";
    
    return 0;   
}
