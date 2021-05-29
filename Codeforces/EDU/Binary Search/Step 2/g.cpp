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
#define MAXN 100

using namespace std;

int k, n, a[MAXN];

bool check(ll m){
    
    if(m == 0) return true;

    ll cont = 0, c = 0;

    for(int i = 0; i < n && cont < k; i++){

        ll aux = a[i];

        if(aux + c >= m){
            cont++;
            aux -= m - c;
            c = min(aux, c);
        }
        else{
            c += aux;
        }
    }

    return cont == k;
}

ll binSearch(ll l, ll r){
    
    while(l < r){

        ll m = l + (r - l)/2;

        if(check(m))
            l = m + 1;
        else
            r = m;
    }

    return l - 1;
}

int main(){
    optimize;
    
    cin >> k >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << binSearch(0LL, INFLL) << "\n";

    return 0;   
}
