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

int n, c;
ll x[MAXN];

bool check(ll d){
    int cont = 1, last = 0;

    for(int i = 1; i < n; i++){
        if(x[last] + d <= x[i]){
            last = i;
            cont++;
        }
    }

    return cont >= c;
}

ll binSearch(ll l, ll r){
    while(l < r){
        ll m = l + (r - l) / 2;
        if(!check(m))
            r = m;
        else
            l = m + 1;
    }
    return l - 1;
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        
        cin >> n >> c;

        for(int i = 0; i < n; i++)
            cin >> x[i];

        sort(x, x + n);

        cout << binSearch(0, INFLL) << "\n";
    }
    
    return 0;   
}
