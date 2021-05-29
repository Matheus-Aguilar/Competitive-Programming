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

string s;
int nb, ns, nc, pb, ps, pc, cb = 0, cs = 0, cc = 0;
ll r;

bool check(ll m){
    ll qb = max(m * cb - nb, 0LL), qs = max(m * cs - ns, 0LL), qc = max(m * cc - nc, 0LL);
    return r - pb * qb - ps * qs - pc * qc >= 0;
}

ll binSearch(ll l, ll r){
    
    while(l < r){
        
        ll m = l + (r - l)/2;

        if(check(m))
            l = m + 1;
        else
            r = m;
    }

    return l - 1;
}

int main(){
    optimize;
    
    cin >> s >> nb >> ns >> nc >> pb >> ps >> pc >> r;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'B') cb++;
        else if(s[i] == 'S') cs++;
        else cc++;
    }

    cout << binSearch(0, r + 110) << "\n";

    return 0;   
}
