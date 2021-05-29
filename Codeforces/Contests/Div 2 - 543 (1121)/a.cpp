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
    
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    vector<int> p(n);
    vector<int> s(n);
    vector<int> c(k);
    vector<priority_queue<pii>> pq(m);

    for(int i = 0; i < n; i++)
        cin >> p[i];
    for(int i = 0; i < n; i++){
        cin >> s[i];
        s[i]--;
    }
    for(int i = 0; i < k; i++){
        cin >> c[i];
        c[i]--;
    }

    for(int i = 0; i < n; i++)
        pq[s[i]].push(pii(p[i], i));
    for(int i = 0; i < k; i++){
        if(c[i] != pq[s[c[i]]].top().second)
            ans++;
    }

    cout << ans << "\n";

    return 0;   
}
