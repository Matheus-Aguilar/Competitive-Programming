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

int solveMin(int n, vector<int> x){

    int ans = 0;

    x.resize(unique(all(x)) - x.begin());

    vector<int> f(n + 3, 0);
    for(int i = 0; i < x.size(); i++)
        f[x[i]]++;

    for(int i = 0; i < x.size(); i++){
        if(f[x[i] - 1]) f[x[i] - 1]++, f[x[i]]--;
        else if(f[x[i] + 1]) f[x[i] + 1]++, f[x[i]]--, i++;
        else if(f[x[i] + 2]) f[x[i] + 1]++, f[x[i]]--;
    }

    for(int i = 0; i <= n + 1; i++)
        if(f[i])
            ans++;

    return ans;
}

int solveMax(int n, vector<int> x){
    int ans = 0;

    vector<int> f(n + 2, 0);
    for(int i = 0; i < n; i++)
        f[x[i]]++;

    for(int i = 0; i < n; i++){
        if(!f[x[i] - 1]) f[x[i] - 1]++, f[x[i]]--;
        else if(f[x[i]] > 1) f[x[i] + 1]++, f[x[i]]--;
    }

    for(int i = 0; i <= n + 1; i++)
        if(f[i])
            ans++;

    return ans;
}

int main(){
    optimize;

    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    sort(all(x));

    cout << solveMin(n, x) << " " << solveMax(n, x) << "\n";

    return 0;   
}
