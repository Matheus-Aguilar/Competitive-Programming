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
#define fi first
#define se second

using namespace std;

bool cmp(const pair<pair<ll, int>, int> &a, const pair<pair<ll, int>, int> &b){
    if(a.fi.fi != b.fi.fi) return a.fi.fi > b.fi.fi;
    if(a.fi.se != b.fi.se) return a.fi.se > b.fi.se;
    return a.se < b.se;
}

int main(){
    optimize;

    ll n, m;
    cin >> n >> m;
    
    vector<pair<pair<ll, int>, int>> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i].fi.fi >> a[i].fi.se;
        a[i].se = i + 1;
    }

    sort(all(a), cmp);

    ll sum = 0;

    int i, j, r = 0, w = 0;

    while(sum < m){
        sum += a[r].fi.fi;
        w += a[r].fi.se;
        r++;
    }

    i = r - 1;
    j = r;

    while(i >= 0 && j < n){
        while(i >= 0 && a[i].fi.se == 1)
            i--;
        while(j < n && a[j].fi.se == 0)
            j++;
        
        if(i < 0 || j >= n) break;
        
        if(sum - a[i].fi.fi + a[j].fi.fi >= m){
            
            w++;

            sum += -a[i].fi.fi + a[j].fi.fi;
            swap(a[i], a[j]);
            
            i--, j++;
        }
        else
            break;
    }

    cout << r << " " << w << "\n";

    for(int i = 0; i < r; i++)
        cout << a[i].se << " \n"[i==r-1];

    return 0;   
}
