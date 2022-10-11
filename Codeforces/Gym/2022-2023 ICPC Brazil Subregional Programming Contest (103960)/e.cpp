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
#define MAXN 1000100

using namespace std;

int n, h[MAXN], f = 0;
pii vals[MAXN];
queue<int> pos[MAXN];

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> h[i];
        vals[i] = make_pair(-h[i], i);
    }

    sort(vals, vals + n);

    for(int i = 0; i < n; i++){
        
        int x = vals[i].second, y = -vals[i].first;

        if(!pos[y + 1].empty() && pos[y + 1].front() < x)
            pos[y + 1].pop();
        else 
            f++;

        pos[y].push(x);
    }
    
    cout << f << "\n";

    return 0;   
}
