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

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main(){
    optimize;

    int b, l;
    cin >> b >> l;

    vector<int> d(l);
    vector<int> p(l, 1);
    vector<int> q(l);

    for(int i = 0; i < l; i++){
        cin >> d[i];
    }

    for(int i = 1; i < l; i++){
        p[i] = (p[i - 1] * b) % (b + 1);
    }

    int s = 0;

    for(int i = 0; i < l; i++){
        int D = d[i] % (b + 1);
        int P = (p[l - i - 1] * D) % (b + 1);
        s = (s + P) % (b + 1);
    }

    if(s == 0){
        cout << 0 << " " << 0 << "\n";
        return 0;
    }

    for(int i = 0; i < l; i++){
        int t;
        int g = gcd(p[i], b + 1, q[i], t);

        if(g != 1){
            q[i] = -1;
            continue;
        }

        while(q[i] < 0){
            q[i] += (b + 1);
        }

        q[i] %= (b + 1);
    }

    int ans = -1, pos = -1;

    for(int i = 0; i < l && ans == -1; i++){

        if(q[i] == -1) continue;

        int m = (s * q[l - i - 1]) % (b + 1);

        if(m <= d[i]){
            ans = d[i] - m;
            pos = i + 1;
        }
    }

    cout << pos << " " << ans << "\n";
    
    return 0;   
}
