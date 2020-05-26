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

char ans[MAXN];
int a[MAXN];
int g[MAXN];

int main(){
    //optimize;

    int n, sa = 0, sg = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d%d", &a[i], &g[i]);
    for(int i = 0; i < n; i++){
        if(abs(sa + a[i] - sg) <= 500){
            sa += a[i];
            ans[i] = 'A';
        }
        else{
            sg += g[i];
            ans[i] = 'G';
        }
    }
    
    ans[n] = '\0';

    printf("%s\n", &ans);

    return 0;   
}
