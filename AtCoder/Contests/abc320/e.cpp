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

struct Event {
    ll t, w, s;
    int type, i;

    bool operator<(const Event &e) const {
        if(t != e.t)
            return t > e.t;
        if(type != e.type)
            return type > e.type;
        return i > e.i;
    }
};

int n, m;
priority_queue<Event, vector<Event>> eq;
priority_queue<int, vector<int>, greater<int>> pq;

ll ans[MAXN];

int main(){
    optimize;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        pq.push(i);

    for(int i = 0; i < m; i++){
        Event e;
        cin >> e.t >> e.w >> e.s;
        e.i = i;
        e.type = 1;
        eq.push(e);
    }

    while(!eq.empty()){
        Event e = eq.top();
        eq.pop();

        if(e.type == 1){
            if(!pq.empty()){
                
                int i = pq.top();
                pq.pop();

                ans[i] += e.w;
                Event e2;

                e2.i = i;
                e2.type = 0;
                e2.t = e.t + e.s;

                eq.push(e2);
            }
        } else {
            pq.push(e.i);
        }
    }
    
    for(int i = 0; i < n; i++)
        cout << ans[i] << "\n";

    return 0;   
}
