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

int r, c, nx, ny, x[MAXN], y[MAXN];
string s;

int solve(int n, int *v, int sz){

    int minx = 0, maxx = 0, cont = 0, ans = 0;

    for(int i = 0; i < n; i++){

        int diff = max(maxx, cont + v[i]) - min(minx, cont + v[i]);

        if(diff >= sz){
            ans++;
            continue;
        }

        minx = min(minx, cont + v[i]);
        maxx = max(maxx, cont + v[i]);
        cont += v[i];
    }

    return ans;
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){

        int ans = 0;

        nx = 0, ny = 0;

        cin >> r >> c >> s;
    
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '<')
                x[nx++] = -1;
            if(s[i] == '>')
                x[nx++] =  1;
            if(s[i] == '^')
                y[ny++] = -1;
            if(s[i] == 'v')
                y[ny++] =  1;
        }

        ans = solve(nx, x, c) + solve(ny, y, r);

        cout << ans << "\n";
    }
    
    return 0;   
}
