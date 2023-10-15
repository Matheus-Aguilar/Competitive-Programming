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
#define MAXN 500500

using namespace std;

int n;
ll r[MAXN], x[MAXN], d[MAXN], ans[MAXN], sum = 0, odd = 0, even = INFLL;
unordered_map<ll, int> freq;

bool check(ll v, int pos = 0){

    if(freq[v] <= 0)
        return false;
    
    freq[v]--;
    ans[pos] = v;

    if(pos == n - 1)
        return true;
    
    bool ok = check(d[pos] - v, pos + 1);

    if(!ok)
        freq[v]++;
    
    return ok;
}

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> x[i];
    for(int i = 0; i < n; i++)
        cin >> r[i];
    for(int i = 0; i < n; i++)
        freq[r[i]]++;
    for(int i = 0; i < n - 1; i++)
        d[i] = x[i + 1] - x[i];
    for(int i = 0; i < n - 1; i++){
        if(i % 2 == 0){
            sum += d[i];
            even = min(sum, even);
        } else {
            sum -= d[i];
            odd = max(odd, sum);
        }
    }

    sort(r, r + n);

    if(!check(r[0])){
        if(!check(even - r[0])){
            check(odd + r[0]);
        }
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] << " \n"[i+1==n];
    
    return 0;   
}
