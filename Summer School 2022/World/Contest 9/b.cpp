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

vector<ll> nums;
vector<int> g;

void precalc(){
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);

    g.push_back(0);
    g.push_back(1);
    g.push_back(2);

    ll val = 2;
    ll diff = 2;

    int mul[] = {1, 3, 2, 2};
    int pos = 0;
    int grundy = 2;

    while(val <= 1000000000000000000LL){
        val += diff;
        diff *= mul[pos];
        pos = (pos + 1) % 4;
        grundy = (grundy + 1) % 4;

        nums.push_back(val);
        g.push_back(grundy);
    }
}

int solve(ll x){
    int pos = upper_bound(all(nums), x) - nums.begin() - 1;
    return g[pos];
}

int main(){
    optimize;
    
    precalc();

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        
        vector<ll> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];
        
        int x = 0LL;

        for(int i = 0; i < n; i++)
            x ^= solve(a[i]);

        cout << (x ? "Henry" : "Derek") << "\n";
    }

    return 0;   
}
