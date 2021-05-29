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

ll p[28];

char solve(int i, int n){
    if(i == 0)
        return 'a';
    if(n == p[i])
        return ('a' + i);
    if(n > p[i])
        return solve(i - 1, n - p[i]);
    return solve(i - 1, n);
}

int main(){
    optimize;

    //S(0) = 1
    //S(n) = 2 * S(n - 1) + 1
    //S(n) = 2 * S(n - 1) + 1 = 4 * S(n - 2) + 3 = 8 * S(n - 3) + 7 = 2^k * S(n - k) + 2^k - 1
    //k = n => S(n) = 2^(n + 1) - 1

    p[0] = 1;

    for(int i = 1; i < 28; i++)
        p[i] = 2 * p[i - 1];

    int n;
    cin >> n;

    cout << solve(25, n) << "\n";

    return 0;   
}
