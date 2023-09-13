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
#define MAXN 1000100

using namespace std;

int n, k, f[MAXN], freq[MAXN];

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
    }

    int ans = 0;

    for(int i = MAXN - 1; i >= 0; i--){
        if(freq[i] >= k){
            ans = i;
            break;
        }
        int nxt = i - calc(i);
        freq[nxt] += freq[i];
        k -= freq[i];
    }

    cout << calc(ans) << "\n";

    return 0;   
}
