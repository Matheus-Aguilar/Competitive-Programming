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

    int n, m;
    cin >> n >> m;
    
    long double avg = 0;
    ll sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++){
        sum1 += i;
        sum2 += abs(i - n/2);
    }
    while(m--){
        ll x, d;
        cin >> x >> d;
        avg += n * x;
        avg += d * (d >= 0 ? sum1 : sum2);
    }

    avg /= n;
    cout << fixed << setprecision(12) << avg << "\n";

    return 0;   
}
