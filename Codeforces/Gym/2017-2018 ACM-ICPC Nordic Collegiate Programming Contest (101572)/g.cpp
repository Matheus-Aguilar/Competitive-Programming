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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

struct Team{
    int idx, pr, pn;
    Team() {}
    Team(int _idx, int _pr, int _pn) : idx(_idx), pr(_pr), pn(_pn) {}
    bool operator<(const Team &t) const {
        if(pr != t.pr) return pr > t.pr;
        if(pn != t.pn) return pn < t.pn;
        return idx < t.idx;
    }
};

#define ordered_set tree<Team, null_type,less<Team>, rb_tree_tag,tree_order_statistics_node_update> 

int main(){
    optimize;

    int n, m;
    cin >> n >> m;

    vector<Team> sum(n);
    ordered_set s;
    
    for(int i = 0; i < n; i++){
        sum[i] = Team(i, 0, 0);
        s.insert(sum[i]);
    }
    
    for(int i = 0; i < m; i++){
        int t, p;
        cin >> t >> p;

        s.erase(sum[t - 1]);

        sum[t - 1].pr++;
        sum[t - 1].pn += p;

        s.insert(sum[t - 1]);

        cout << s.order_of_key(sum[0]) + 1 << "\n";
    }
    
    return 0;   
}
