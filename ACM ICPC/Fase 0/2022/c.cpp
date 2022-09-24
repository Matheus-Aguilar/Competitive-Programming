#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000009
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

int n, q;
ll pot[62];

ll v = 0, p = 1;
ll maxN = (1LL << n);
ll mask = 0;

void precalc(){
    pot[0] = 1;
    
    for(int i = 1; i < 62; i++){
        pot[i] = pot[i - 1] * 2;
    }

    for(int i = 0; i < n; i++){
        mask <<= 1;
        mask |= 1;
    }
}

int getLevel(ll x){

    int l = 0, r = n;

    while(l < r){
        int m = l + (r - l) / 2;
        if(x % pot[m] == 0)
            l = m + 1;
        else
            r = m;
    }

    return l - 1;
}

int main(){
    
    scanf("%d%d", &n, &q);
    
    precalc();

    while(q--){
        ll ans = 0;

        ll q1, q2;
        scanf("%lld%lld", &q1, &q2);

        if(q1 != q2){
            if(q1 == 0){
                ans = n - getLevel(q2);
            } else if(q2 == 0){
                ans = n - getLevel(q1);
            } else {
                int l1 = getLevel(q1), l2 = getLevel(q2);

                if(l1 > l2){
                    swap(l1, l2);
                    swap(q1, q2);
                }

                ans += l2 - l1;
                q1 = ((q1 & (mask >> (l2 - l1))) << (l2 - l1));

                if(q1 != q2)
                    ans += 2 * (n - getLevel(abs(q1 - q2)));
            }
        }

        v = (v + (ans * p) mod) mod;
        p = (p * n) mod;
    }

    printf("%lld\n", v);
    
    return 0;   
}
