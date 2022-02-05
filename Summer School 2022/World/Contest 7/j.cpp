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
#define MAXN 500

using namespace std;

int n, l, p, a[MAXN][MAXN], b[MAXN][MAXN], sa = 0, sb = 0;

int main(){
    optimize;
    
    cin >> n >> l >> p;

    for(int i = 0; i < l; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            sa += a[i][j];
        }
    }

    for(int i = 0; i < p; i++){
        for(int j = 0; j < n; j++){
            cin >> b[i][j];
            sb += b[i][j];
        }
    }
    
    return 0;   
}
