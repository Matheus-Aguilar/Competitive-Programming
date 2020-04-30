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

int main(){
    optimize;

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<pii> seq(1, pii(0, 0));
    int ans = 1;
    for(int i = 1; i < n; i++){
        if(a[i - 1] >= a[i]){
            ans = max(ans, i - seq.back().first);
            seq.back().second = i - 1;
            seq.emplace_back(i, 0);
        }
    }
    ans = max(ans, n - seq.back().first);
    seq.back().second = n - 1;

    for(int i = 1; i < seq.size(); i++){
        if(seq[i - 1].first != seq[i - 1].second && seq[i].first != seq[i].second){
            if(a[seq[i - 1].second - 1] < a[seq[i].first] || a[seq[i - 1].second] < a[seq[i].first + 1])
                ans = max(ans, seq[i].second - seq[i - 1].first);
        }
    }
    cout << ans << "\n";

    return 0;   
}
