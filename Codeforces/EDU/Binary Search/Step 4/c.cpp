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
#define MAXN 100010

using namespace std;

int n, k, a[MAXN], b[MAXN];
double val[MAXN];

bool check(double m){
    
    for(int i = 0; i < n; i++)
        val[i] = a[i] - m * b[i];

    sort(val, val + n, greater<double>());

    return accumulate(val, val + k, 0.0) >= 0;
}

double binSearch(double l, double r){
    
    double m;

    for(int i = 0; i < 150; i++){
        m = l + (r - l)/2;

        if(check(m))
            l = m;
        else
            r = m;
    }
    
    return l;
}

int main(){
    optimize;
    
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    cout << fixed << setprecision(9) << binSearch(0, INF) << "\n";

    return 0;   
}
