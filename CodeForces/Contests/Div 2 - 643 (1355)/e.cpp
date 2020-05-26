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

ll n, r, a, m, hMax = 0, sum, h[MAXN];

ll f(ll x){
    ll cost =0, mov = 0, diff;
    if(sum < n * x){
        diff = n * x - sum;
        for(int i = 0; i < n; i++){
            if(h[i] < x && diff > 0){
                ll add = min(diff, (x - h[i]));
                cost += a * add;
                diff -= add;
                mov += x - h[i] - add;
            }
            else{
                mov += abs(x - h[i]);
            }
        }
    }
    else{
        diff = sum - n * x;
        for(int i = 0; i < n; i++){
            if(h[i] > x && diff > 0){
                ll rem = min(diff, (h[i] - x));
                cost += r * rem;
                diff -= rem;
                mov += h[i] - x - rem;
            }
            else{
                mov += abs(x - h[i]);
            }
        }
    }
    return cost + m * (mov/2LL);
}

ll ternarySearch(int l, int r){
    while(l < r){
        int m1 = l + (r - l)/3;
        int m2 = r - (r - l)/3;

        ll f1 = f(m1);
        ll f2 = f(m2);

        if(f1 > f2)
            l = m1 + 1;
        else
            r = m2 - 1;
    }
    return f(l);
}

int main(){
    optimize;

    cin >> n >> a >> r >> m;
    for(int i = 0; i < n; i++){
        cin >> h[i];
        hMax = max(hMax, h[i]);
    }

    m = min(m, r + a);
    sum = accumulate(h, h + n, 0LL);

    cout << ternarySearch(0, hMax + 1) << "\n";

    return 0;   
}
