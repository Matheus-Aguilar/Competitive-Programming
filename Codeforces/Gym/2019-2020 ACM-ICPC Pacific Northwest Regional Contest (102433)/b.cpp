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

int k, n, a[MAXN], last[MAXN], ans[MAXN], sz = 0;
bool vis[MAXN], ended[MAXN];

int main(){
    optimize;

    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
        last[a[i]] = i;
    }

    for(int i = 0; i < n; i++){
        if(i == last[a[i]])
            ended[a[i]] = true;
        if(vis[a[i]])
            continue;
        while(sz > 0 && ans[sz - 1] > a[i] && !ended[ans[sz - 1]]){
            vis[ans[sz - 1]] = false;
            sz--;
        }
        ans[sz++] = a[i];
        vis[a[i]] = true;
    }

    for(int i = 0; i < k; i++)
        cout << ans[i] << " ";
    
    cout << "\n";

    return 0;   
}