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
#define MAXN 100100

using namespace std;

int f[MAXN], cont[MAXN];
string s;

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        pii ans = make_pair(-1, -1);

        for(int i = 0; i < n; i++)
            cin >> s >> f[i];
        
        for(int i = 0; i < n; i++){
            cont[f[i]]++;
            ans = max(ans, make_pair(cont[f[i]], -f[i]));
        }
        
        for(int i = 0; i < n; i++)
            cont[f[i]]--;
        
        cout << -ans.second << "\n";
    }
    
    return 0;   
}
