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

int ans[MAXN], m;
string s1[MAXN], s2[MAXN];
map<string, bool> vis;

int main(){
    optimize;
    
    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> s1[i];

        for(int i = 0; i < n; i++)
            cin >> s2[i];

        m = 0;

        int l = 0, r = -1, sz = 1;
        
        while(l < n || r < n){
            if(!vis[s1[l]]){
                r++;
                vis[s2[r]] = true;
            }
            else {
                if(l < r){
                    l++;
                    sz++;
                }
                else {
                    ans[m++] = sz;
                    sz = 1;
                    l++;
                }
            }
        }

        for(int i = 0; i < m; i++)
            cout << ans[i] << " \n"[i==m-1];

        vis.clear();
    }

    return 0;   
}
