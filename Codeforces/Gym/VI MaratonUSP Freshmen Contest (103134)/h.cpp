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

    vector<pii> ev(n);

    for(int i = 0; i < n; i++)
        cin >> ev[i].first >> ev[i].second;
    
    sort(all(ev));

    int ans = 0;
    pair<int, int> seg = ev[0];

    for(int i = 1; i < n; i++){
        if(seg.second > ev[i].first){
            seg.second = max(seg.second, ev[i].second);
        } else {

            int a = (seg.first + 4) / 5;
            int b = (seg.second - 1) / 5;
            ans = max(b - a + 1, ans);

            seg = ev[i];
        }
    }

    int a = (seg.first + 4) / 5;
    int b = (seg.second - 1) / 5;
    ans = max(b - a + 1, ans);

    cout << ans << "\n";
    
    return 0;   
}
