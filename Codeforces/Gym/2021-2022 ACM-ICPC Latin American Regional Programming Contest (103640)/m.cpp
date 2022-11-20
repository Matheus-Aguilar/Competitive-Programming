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

struct Task {
    ll t, d, p;
    int id;

    bool operator<(const Task &task){
        if(d != task.d) return d < task.d;
        return id < task.id;
    }
};

int main(){
    optimize;

    int n;
    cin >> n;

    vector<Task> t(n);

    for(int i = 0; i < n; i++){
        cin >> t[i].t >> t[i].d;
        t[i].id = i + 1;
    }

    sort(all(t));

    for(int i = 0; i < n; i++){
        
        t[i].p = t[i].t + (i == 0 ? 0 : t[i - 1].p);
        
        if(t[i].p > t[i].d){
            cout << "*" << "\n";
            return 0;
        }
    }

    vector<bool> vis(n, false);
    vector<int> ans;

    for(int k = 0; k < n; k++){
        
        int best = -1;
        ll diff = INFLL;

        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            
            if(diff >= t[i].t){
                if(best == -1 || t[best].id > t[i].id){
                    best = i;
                }
            }

            diff = min(diff, t[i].d - t[i].p);
        }

        vis[best] = true;

        for(int i = 0; i < best; i++)
            t[i].p += t[best].t;

        ans.push_back(t[best].id);
    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << " \n"[i==n-1];
    }

    return 0;   
}
