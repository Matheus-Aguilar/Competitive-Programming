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
#define MAXN 300100

using namespace std;

int n;
ll p[MAXN];

int main(){
    optimize;


    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i];
    sort(p + 1, p + n + 1);
    cout << p[(n + 1)/2] << "\n";
    
    return 0;   
}
