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
#define MAXN 1001001

using namespace std;

int n, k, f[MAXN], pos[MAXN], freq[MAXN];

int calc(int x){
    int sum = 0;
    while(x > 0){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main(){
    optimize;

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> f[i];
        freq[f[i]]++;
        pos[f[i]]++;
    }

    for(int i = MAXN - 2; i >= 0; i--){
        int nxt = i - calc(i);
        pos[i] += pos[i + 1];
        pos[nxt] += freq[i];
        freq[nxt] += freq[i];
    }

    int val = 0;

    for(int i = 0; i < MAXN; i++){
        if(pos[i] >= k)
            val = i;
    }

    cout << calc(val) << "\n";

    return 0;   
}
