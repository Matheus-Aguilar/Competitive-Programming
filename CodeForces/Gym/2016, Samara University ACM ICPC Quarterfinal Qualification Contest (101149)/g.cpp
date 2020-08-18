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

struct Event{
    int w, c, t, i;
    Event(int _w = 0, int _c = 0, int _t = 0, int _i = 0) : w(_w), c(_c), t(_t), i(_i){}
    bool operator<(const Event &e) const{
        if(w != e.w) return w < e.w;
        if(c != e.c) return c < e.c;
        return t < e.t;
    }
};

int main(){
    optimize;
    
    int n, m;
    cin >> n;

    vector<pii> z(n);
    vector<pii> a(m);
    vector<int> ans(n, -1);
    vector<Event> e(n + m);

    for(int i = 0; i < n; i++){
        cin >> z[i].first >> z[i].second;
        e.push_back(Event(z[i].first, z[i].second, 0, i));
    }

    cin >> m;

    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        e.push_back(Event(a[i].first, a[i].second, 1, i));
    }

    sort(all(e));

    set<pii> s;

    for(int i = 0; i < n + m; i++){
        if(e[i].t == 0){
            s.insert(pii(e[i].c, e[i].i));
        }
        else{
            auto it = s.lower_bound(pii(e[i].c, INF));
            if(it != s.begin()){
                it--;
                ans[it->second] = e[i].i;
                s.erase(it);
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(ans[i] == -1){
            cout << -1 << "\n";
            return 0;
        }
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i==n-1];

    return 0;   
}
