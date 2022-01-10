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

    int n, k;
    cin >> n >> k;

    vector<vector<int>> a(k);
    vector<int> ans(n);
    vector<int> c(n);
    vector<int> cont(k, 0);

    for(int i = 0; i < n; i++){
        int r;
        cin >> r >> c[i];
        c[i]--;
        a[c[i]].push_back(r);
    }

    for(int i = 0; i < k; i++){
        sort(all(a[i]));
    }

    for(int i = 0; i < n; i++){
        ans[i] = a[c[i]][cont[c[i]]];
        cont[c[i]]++;
    }

    bool ok = true;

    for(int i = 0; i < n - 1 && ok; i++){
        if(ans[i] > ans[i + 1]){
            ok = false;
        }
    }

    cout << (ok ? 'Y' : 'N') << "\n";
    
    return 0;   
}
