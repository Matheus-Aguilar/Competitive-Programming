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
#define MAXN 10010

using namespace std;

int n, k, a[MAXN];

bool check(double m){

    if(m == 0.0) return false;

    ll sum = 0;

    for(int i = 0; i < n; i++)
        sum += (ll)(a[i] / m);

    return sum >= k;
}

double binSearch(double l, double r){
    
    for(int k = 0; k < 150; k++){
        double m = l + (r - l)/2;

        if(check(m))
            l = m;
        else
            r = m;
    }
    
    return (l + r)/2;
}

int main(){
    optimize;
    
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    cout << fixed << setprecision(9) << binSearch(0, INF) << "\n";

    return 0;   
}
