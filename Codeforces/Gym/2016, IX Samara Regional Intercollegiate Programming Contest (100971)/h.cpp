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
    int x, t, i;
    Event() {}
    Event(int _x, int _t, int _i) : x(_x), t(_t), i(_i) {}
    bool operator<(const Event &ev) {
        if(x != ev.x) return x < ev.x;
        if(t != ev.t) return t < ev.t;
        return i < ev.i;
    }    
};

int n, bit[MAXN], ne = 0, cont = 0;
Event e[4 * MAXN];

void update(int x, int v){
    while(x < MAXN){
        bit[x] += v;
        x += -x & x;
    }
}

int getKth(int k){

    int kth = 0;
    
    for(int i = 30; i >= 0; i--){
        int idx = kth + (1 << i);
        if(idx < MAXN && bit[idx] < k){
            k -= bit[idx];
            kth = idx;
        }
    }

    return kth + 1;
}

void rem(int x){
    update(x, -1);
    cont--;
}

void add(int x){
    update(x, 1);
    cont++;
}

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++){
        
        int a, b;
        cin >> a >> b;

        e[ne++] = Event(a, 0, i + 1); // In
        e[ne++] = Event(b, 2, i + 1); // Out
        e[ne++] = Event(i + 1, 1, 0); // Query
    }

    sort(e, e + ne);

    for(int i = 0; i < ne; i++){
        if(e[i].t == 0){
            add(e[i].i);
        } else if(e[i].t == 2){
            rem(e[i].i);
        } else {
            if(cont < e[i].x)
                cout << -1 << " ";
            else
                cout << getKth(e[i].x) << " ";
        }
    }

    cout << "\n";

    return 0;   
}
