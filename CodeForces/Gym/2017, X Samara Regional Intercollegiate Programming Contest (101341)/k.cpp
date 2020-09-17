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
#define MAXN 200010

using namespace std;

ll c[MAXN];
bool ok[MAXN];
pair<ll, ll> dp[MAXN];
int nxt[MAXN];
bool peguei[MAXN];

struct Contest{
    int l, r, i;
    Contest(int l = 0, int r = 0, int i = 0){
        this->l = l;
        this->r = r;
        this->i = i;
    }
    bool operator<(const Contest &c) const{
        if(l != c.l) return l < c.l;
        if(r != c.r) return r < c.r;
        return i < c.i;
    }
};

vector<Contest> v;

pair<ll, ll> solve(int i){
    if(i == v.size())
        return pair<ll, ll>(0, 0);
    if(!ok[i]){
        pair<ll, ll> nget = solve(i + 1), get = solve(nxt[i]);

        get.first += c[v[i].i];
        get.second += v[i].r - v[i].l;

        if(nget.first > get.first){
            dp[i] = nget;
            peguei[i] = false;
        }
        else if(nget.first < get.first){
            dp[i] = get;
            peguei[i] = true;
        }
        else if(nget.second < get.second){
            dp[i] = nget;
            peguei[i] = false;
        }
        else{
            dp[i] = get;
            peguei[i] = true;
        }

        ok[i] = true;
    }
    return dp[i];
}

int main(){
    optimize;

    int n;
    cin >> n;
    
    v.resize(n);

    for(int i = 0; i < n; i++){
        cin >> v[i].l >> v[i].r >> c[i];
        v[i].i = i;
    }

    sort(all(v));

    for(int i = 0; i < n; i++)
        nxt[i] = lower_bound(all(v), Contest(v[i].r, -INF, -INF)) - v.begin();

    ms(ok, 0);
    ms(peguei, false);

    pair<ll, ll> best = solve(0);
    vector<int> sol;

    int pos = 0;

    while(pos < n){
        if(peguei[pos]){
            sol.push_back(v[pos].i + 1);
            pos = nxt[pos];
        }
        else
            pos++;
    }

    cout << sol.size() << " " << best.first << " " << best.second << "\n";
    for(auto i:sol)
        cout << i << " ";
    cout << "\n";

    return 0;
}
