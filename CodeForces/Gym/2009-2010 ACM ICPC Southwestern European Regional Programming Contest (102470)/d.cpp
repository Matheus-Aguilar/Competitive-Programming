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
#define MAXN 1100

using namespace std;

int p[20] = {20, 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5};

long double dp2[502][MAXN];
long double dp2[502][MAXN];

int main(){
    optimize;

    for(int j = 0; j < MAXN; j++)
        dp1[0][j] = dp2[0][j] = 1;

    for(int i = 1; i <= 501; i++)
        for(int j = MAXN - 1; j >= 0; j--)
            for(int k = 0; k < 20; k++)
                dp1[i][j] += (i - p[k] >= 0 ? dp1[i - p[k]][j + 1]/20.0L : dp1[i][j + 1]/20.0L);
    
    for(int i = 1; i <= 501; i++)
        for(int j = MAXN - 1; j >= 0; j--)
            for(int k = 0; k < 20; k++)
                dp2[i][j] = max(dp2[i][j], (i - p[k] >= 0 ? dp2[i - p[k]][j + 1]/3.0L) + () + ())


    return 0;   
}
