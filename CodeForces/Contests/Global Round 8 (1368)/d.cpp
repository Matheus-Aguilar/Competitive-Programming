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
#define MAXN 200100

using namespace std;

ll a[MAXN];
ll b[MAXN];

int main(){
    optimize;

    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < 30; i++){
        int cont = 0;
        for(int j = 0; j < n; j++){
            if(a[j] & (1 << i))
                cont++;
        }
        for(int j = 0; j < cont; j++)
            b[j] |= (1 << i);
    }

    ll sum = 0;
    for(int i = 0; i < n; i++)
        sum += b[i] * b[i];

    cout << sum << "\n";

    return 0;   
}
