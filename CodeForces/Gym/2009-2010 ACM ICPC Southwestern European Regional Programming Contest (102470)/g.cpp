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

using namespace std;

int main(){
    optimize;

    int n;
    long double x0, y0, ans = 0.0L;

    cin >> n >> x0 >> y0;

    vector<long double> y(n);
    vector<pair<long double, long double>> x(n);

    for(int i = 0; i < n; i++)
        cin >> y[i] >> x[i].first >> x[i].second;

    for(int i = 0; i < n; i++){
        if(abs(x0 - x[i].first) <)
    }

    return 0;   
}
