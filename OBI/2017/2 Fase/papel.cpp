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

    int n, best = 2, now = 2;
    cin >> n;

    vector<pii> c(n + 1);
    vector<bool> v(n + 2, true);
    for(int i = 1; i <= n; i++){
        cin >> c[i].first;
        c[i].second = i;
    }

    sort(all(c));

    v[0] = v[n + 1] = false;

    for(int i = 1; i < n; i++){
        int pos = c[i].second;
        if(v[pos - 1] && v[pos + 1])
            now++;
        else if(!v[pos - 1] && !v[pos + 1])
            now--;
        v[pos] = false;
        if(c[i].first != c[i + 1].first)
            best = max(best, now);
    }

    cout << best << "\n";
    
    return 0;   
}
