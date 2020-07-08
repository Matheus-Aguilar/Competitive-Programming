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
#define MAXN 300100

using namespace std;

int n;
ll p[MAXN];

ll f(ll x){
    ll sum = 0;
    for(int i = 0; i < n; i++)
        sum += abs(p[i] - x);
    return sum;
}

ll ternarySearch(ll start, ll end){
    while(start < end){
        ll m1 = start + (end - start)/3LL;
        ll m2 = end - (end - start)/3LL;
 

        ll f1 = f(m1);
        ll f2 = f(m2);
 
        if(f1 > f2)
            start = m1 + 1;
        else
            end = m2 - 1;
    }
    return (start <= end ? start : end);
}

int main(){
    optimize;

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    cout << ternarySearch(-INF, INF) << "\n";
    
    return 0;   
}