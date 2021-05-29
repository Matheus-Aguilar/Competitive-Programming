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

struct interval{
    int size;
    int pos;
    bool left;
    interval(int s, int p, bool l): size(s), pos(p), left(l){}
    bool operator<(const interval &i){
        return size < i.size;
    }
};

int main(){
    optimize;

    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    vector<int> h(m);
    vector<interval> in;
    
    for(int i = 0; i < n; i++) cin >> x[i];
    sort(all(x));

    in.emplace_back(INF, x[0], false);
    in.emplace_back(INF, x[n - 1], true);
    for(int i = 0; i < n - 1; i++){
        int sz = (x[i + 1] - x[i] - 1);
        int a = sz/2;
        int b = sz - a;

        if(a) in.emplace_back(a, x[i], true);
        if(b) in.emplace_back(b, x[i + 1], false);
    }

    sort(all(in));

    ll ans = 0;
    int ini = 0;
    int d = 1;
    int j = 0;

    while(j < m){
        for(int i = ini; i < in.size() && j < m; i++){
            ans += d;
            in[i].size--;
            if(!in[i].size) ini++;
            h[j++] = in[i].pos + d * (in[i].left ? 1 : -1);
        }
        d++;
    }

    cout << ans << "\n";
    for(int i = 0; i < m; i++)
        cout << h[i] << " ";
    cout << "\n";

    return 0;   
}
