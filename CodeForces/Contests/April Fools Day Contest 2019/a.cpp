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

vector<int> a;

bool sorted(int l, int r){
    for(int i = l; i < r - 1; i++)
        if(a[i] > a[i + 1])
            return false;
    return true;
}

int solve(int l, int r){
    if(sorted(l, r)) return r - l;
    int m = (r + l)/2;
    return max(solve(l, m), solve(m, r));
}

int main(){
    optimize;
    
    int n;
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    cout << solve(0, n) << "\n";

    return 0;   
}
