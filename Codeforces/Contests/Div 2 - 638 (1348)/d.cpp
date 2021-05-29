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

bool check(int x, int q, int s, int n){
    return s + 2 * (x + q) <= n;
}

int binSearch(int l, int r, int q, int s, int n){
    while(l < r){
        int m = l + (r - l)/2;
        if(check(m, q, s, n))
            l = m + 1;
        else
            r = m;
    }
    return l - 1;
}

int main(){
    optimize;

    int t;
    cin >> t;
    while(t--){
        int n, d = 1, q = 1, s = 1;
        vector<int> ans;
        
        cin >> n;

        while(s + 2 * q < n){
            ans.push_back(binSearch(0, q + 1, q, s, n));
            q += ans.back();
            s += q;
            d++;
        }

        ans.push_back(n - s - q);

        cout << d << "\n";
        for(int i = 0; i < d; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;   
}
