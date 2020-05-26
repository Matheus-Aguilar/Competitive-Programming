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

struct seg{
    ll l, r;
    seg(int _l, int _r): l(_l), r(_r){}
    seg(const seg &o){ l = o.l, r = o.r; }
    bool operator<(const seg &o) const{
        if(r - l + 1 != o.r - o.l + 1) return r - l + 1 > o.r - o.l + 1;
        return l < o.l; 
    }
    ll sz(){
        return r - l + 1;
    }
};

int main(){
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n, 0);
        set<seg> s;
        s.insert(seg(1, n));
        int i = 1;
        while(!s.empty()){
            seg best = *(s.begin());
            ll middle;
            if(best.sz() % 2 != 0)
                middle = (best.l + best.r)/2; 
            else
                middle = (best.l + best.r - 1)/2;
            a[middle - 1] = i++;
            if(best.l <= middle - 1)
                s.insert(seg(best.l, middle - 1));
            if(best.r >= middle + 1)
                s.insert(seg(middle + 1, best.r));
            s.erase(best);
        }
        for(int ai:a) cout << ai << " ";
        cout << "\n";
    }

    return 0;   
}
