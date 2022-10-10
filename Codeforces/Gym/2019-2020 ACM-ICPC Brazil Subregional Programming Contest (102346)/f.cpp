#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>
#define MAXN 100100

using namespace std;

struct Event{
    ll i, j, h;
    ll val;
    Event(ll I, ll J, ll H, ll V):i(I), j(J), h(H), val(V){}
    bool operator<(Event &e){
        return h < e.h;
    }
};

struct River{
    ll x0, y0, x, y;
};

ll n, xMin, yMin, xMax, yMax, p;
ll segtree[4 * MAXN];
ll sum[4 * MAXN];
vector<Event> events;
River rivers[MAXN];

void update(int node, int l, int r, int start, int end, int val){
    
    if(l > r) return;
    
    //Está contido na range
    if(l == start && r == end){
        segtree[node] += val;
        if(segtree[node]) sum[node] = end + 1 - start;
        else if(start == end) sum[node] = 0; //Folha
        else sum[node] = sum[2 * node] + sum[2 * node + 1];
        return;
    }
    
    int middle = start + (end - start)/2;
    
    //Atualiza os filhos
    update(2 * node, l, min(r, middle), start, middle, val);
    update(2 * node + 1, max(l, middle + 1), r, middle + 1, end, val);

    if(segtree[node]) sum[node] = end + 1 - start;
    else if(start == end) sum[node] = 0; //Folha
    else sum[node] = sum[2 * node] + sum[2 * node + 1];
}

bool check(int r){

    ll area = 0;
    ll tam = 0;
    
    events.clear();
    
    for(int i = 0; i < n; i++){
        int yBot = max(yMin, rivers[i].y0 - r);
        int yTop = min(yMax, rivers[i].y + r);
        int xLef = max(xMin, rivers[i].x0 - r);
        int xRig = min(xMax, rivers[i].x + r); 

        if(yBot > yTop || xLef > xRig) continue;

        events.push_back(Event(xLef, xRig, yBot, 1));
        events.push_back(Event(xLef, xRig, yTop, -1));
    }

    sort(events.begin(), events.end());
    
    memset(segtree, 0, sizeof(segtree));
    memset(sum, 0, sizeof(sum));

    for(int i = 0; i < events.size(); i++){
        ll I = events[i].i;
        ll J = events[i].j - 1;
        
        update(1, I, J, 0, MAXN, events[i].val);
        area += sum[1] * (events[i + 1].h - events[i].h);
    }

    return area >= p;
}

int binSearch(int start, int end){
    while(start < end){
        int middle = start + (end - start)/2;
        if(check(middle))
            end = middle;
        else
            start = middle + 1;
    }
    return start;
}

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> rivers[i].x0 >> rivers[i].y0 >> rivers[i].x >> rivers[i].y;
    }

    cin >> p >> xMin >> yMin >> xMax >> yMax;

    p = (ll)(ceil((xMax - xMin) * (yMax - yMin) * p/100.0));

    cout << binSearch(0, 1000000) << "\n";

    return 0;   
}
