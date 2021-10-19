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

struct cmp{
    bool operator()(const pii &a, const pii &b){
        if(a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    }
};

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n, q;
        cin >> n >> q;

        vector<pii> pt(n);
        vector<int> w(q + 1);
        set<pii, cmp> s;

        for(int i = 0; i < n; i++){
            pt[i] = make_pair(0, i);
            s.insert(pt[i]);
        }

        w[0] = s.begin()->second;

        for(int i = 1; i <= q; i++){
            int x, p;
            cin >> x >> p;

            s.erase(pt[x - 1]);
            pt[x - 1].first += p;
            s.insert(pt[x - 1]);

            w[i] = s.begin()->second;
        }

        int ans = q;

        while(ans >= 0){
            if(w[ans] != w[q]){
                break;
            }
            ans--;
        }

        cout << ans + 1 << "\n";
    }
    
    return 0;   
}
