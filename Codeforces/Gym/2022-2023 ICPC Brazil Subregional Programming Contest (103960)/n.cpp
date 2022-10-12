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

int n, k, l, a[MAXN], b[MAXN];
ll ans = 0, sum = 0;
multiset<int> big;
multiset<int, greater<int>> small;

void add(int x){
    sum += a[x];

    big.insert(b[x]);
    sum += b[x];

    if(big.size() > l){
        auto it = big.begin();
        sum -= *it;
        small.insert(*it);
        big.erase(it);
    }
}

void rem(int x){
    sum -= a[x];

    auto it = big.find(b[x]);
    
    if(it != big.end()){
        sum -= *it;
        big.erase(it);

        if(!small.empty()){
            auto it2 = small.begin();
            sum += *it2;
            big.insert(*it2);
            small.erase(it2);
        }
    } else {
        auto it2 = small.find(b[x]);
        small.erase(it2);
    }
}

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int i = 0; i < n; i++)
        cin >> b[i];
    
    cin >> k >> l;

    for(int i = 0; i < k; i++){
        add(i);
    }

    ans = sum;

    for(int i = k - 1, j = n - 1; i >= 0; i--, j--){
        add(j);
        rem(i);
        ans = max(ans, sum);
    }

    cout << ans << "\n";

    return 0;   
}
