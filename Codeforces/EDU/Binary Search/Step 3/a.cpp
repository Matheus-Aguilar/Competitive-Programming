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

const int K = 150;

int n, x[MAXN], v[MAXN];

bool check(double m){

    double l = -INF, r = INF;

    for(int i = 0; i < n; i++){
        l = max(l, x[i] - v[i] * m);
        r = min(r, x[i] + v[i] * m);
    }

    return l <= r;
}

double binSearch(double l, double r){
    
    double m;

    for(int i = 0; i < K; i++){
        
        m = l + (r - l)/2;

        if(check(m))
            r = m;
        else
            l = m;
    }

    return m;
}

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> x[i] >> v[i];

    cout << fixed << setprecision(9) << binSearch(0, INF) << "\n";
    
    return 0;   
}
