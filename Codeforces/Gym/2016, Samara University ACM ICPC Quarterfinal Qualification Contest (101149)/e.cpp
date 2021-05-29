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

    int n, best = 0;
    cin >> n;

    vector<pii> events(2 * n);
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;
        events[2 * i] = pii(-l, 1);
        events[2 * i + 1] = pii(-r, 0);
    }

    sort(all(events));
    
    for(int i = 0; i < n; i++){
        if(events[i].second == 0)
            best++;
        else
            break;
    }

    cout << best << "\n";

    return 0;   
}
