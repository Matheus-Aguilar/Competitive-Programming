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
#define MAXN 200200

using namespace std;

int n, l[MAXN], r[MAXN], a[MAXN], b[MAXN], q, x[MAXN], check[MAXN];
set<pii, greater<pii>> portals;
map<int, int> vals, nxt;

struct Event{
    int pos, type, id;
    Event() {}
    Event(int _pos, int _type, int _id) : pos(_pos), type(_type), id(_id) {}
    bool operator<(const Event &e) {
        if(pos != e.pos)
            return pos < e.pos;
        if(type != e.type)
            return type < e.type;
        return id < e.id;
    }
};

int get(int i){
    if(vals.find(i) == vals.end())
        vals[i] = get(nxt[i]);
    return vals[i];
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){

        cin >> n;

        vector<Event> e;

        for(int i = 0; i < n; i++){
            cin >> l[i] >> r[i] >> a[i] >> b[i];
            e.emplace_back(l[i], 0, i);
            e.emplace_back(r[i], 2, i);
            e.emplace_back(b[i], 1, -1);
        }
        
        cin >> q;

        for(int i = 0; i < q; i++){
            cin >> x[i];
            e.emplace_back(x[i], 1, i);
        }

        sort(all(e));

        portals.clear();
        vals.clear();
        nxt.clear();

        for(int i = 0; i < e.size(); i++){

            int id = e[i].id;

            if(e[i].type == 0){
                portals.emplace(b[id], id);
            } else if(e[i].type == 2){
                portals.erase(make_pair(b[id], id));
            } else {
                if(portals.empty() || portals.begin()->first <= e[i].pos)
                    vals[e[i].pos] = e[i].pos;
                else
                    nxt[e[i].pos] = portals.begin()->first;
            }
        }

        for(int i = 0; i < q; i++){
            cout << get(x[i]) << " \n"[i+1==q];
        }
    }
    
    return 0;   
}
