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
#define MAXN 1000

using namespace std;

struct Event{
    int x, t;
    Event(int _x = 0, int _t = 0) : x(_x), t(_t) {}
    bool operator<(const Event &e) const {
        if(x != e.x) return x < e.x;
        return t < e.t;
    }
};

int main(){
    optimize;

    int n;
    cin >> n;
    
    vector<Event> e;

    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;

        e.emplace_back(a, 0);
        e.emplace_back(b, 2);
    }

    for(int i = 0; i <= MAXN; i++){
        e.emplace_back(i, 1);
    }

    sort(all(e));

    int active = 0, best = -1;

    for(int i = 0; i < e.size(); i++){
        if(e[i].t == 0){
            active++;
        }
        else if(e[i].t == 2){
            active--;
        }
        else{
            if(e[i].x == active){
                best = e[i].x;
            }
        }
    }

    cout << best << "\n";

    return 0;   
}
