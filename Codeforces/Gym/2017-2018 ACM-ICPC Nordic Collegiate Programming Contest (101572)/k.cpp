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
#define MAXN 100100

using namespace std;

int t, a[3], v[3], s[3], c[MAXN];
pair<int, pii> op[6];

bool check(int m){
    
    v[0] = a[0];
    v[1] = a[1];
    v[2] = a[2];

    for(int i = 0; i < t; i++){
        
        bool ok = false;
        
        for(int j = 0; j < 6 && !ok; j++){
            
            pii p = op[j].second;

            if(p.first == p.second && v[p.first] >= 2 && 2 * s[p.first] * c[i] >= m){
                v[p.first] -= 2;
                ok = true;
            }
            else if(p.first != p.second && v[p.first] >= 1 && v[p.second] >= 1 && (s[p.first] + s[p.second]) * c[i] >= m){
                v[p.first] -= 1;
                v[p.second] -= 1;
                ok = true;
            }
        }

        if(!ok) 
            return false;
    }

    return true;
}

int binSearch(int l, int r){
    while(l < r){
        int m = l + (r - l) / 2;
        if(!check(m))
            r = m;
        else
            l = m + 1;
    }
    return l - 1;
}

int main(){
    optimize;

    cin >> a[0] >> a[1] >> a[2];
    cin >> s[0] >> s[1] >> s[2];

    t = (a[0] + a[1] + a[2]) / 2;

    for(int i = 0; i < t; i++)
        cin >> c[i];
    
    sort(c, c + t, greater<int>());

    op[0] = make_pair(s[0] + s[0], make_pair(0, 0));
    op[1] = make_pair(s[0] + s[1], make_pair(0, 1));
    op[2] = make_pair(s[0] + s[2], make_pair(0, 2));
    op[3] = make_pair(s[1] + s[1], make_pair(1, 1));
    op[4] = make_pair(s[1] + s[2], make_pair(1, 2));
    op[5] = make_pair(s[2] + s[2], make_pair(2, 2));

    sort(op, op + 6);

    cout << binSearch(0, INF) << "\n";

    return 0;
}
