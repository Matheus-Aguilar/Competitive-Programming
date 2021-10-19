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

struct Trade{
    int c1, c2;
    double r;
};

int main(){
    optimize;

    int n, cont = 0;
    cin >> n;

    vector<Trade> t(n);
    map<string, int> idx;

    idx["pink"] = cont++;
    idx["blue"] = cont++;

    for(int i = 0; i < n; i++){
        string c1, c2;
        double r;

        cin >> c1 >> c2 >> r;

        if(idx.find(c1) == idx.end()){
            idx[c1] = cont++;
        }

        if(idx.find(c2) == idx.end()){
            idx[c2] = cont++;
        }

        t[i].c1 = idx[c1];
        t[i].c2 = idx[c2];
        t[i].r = r;
    }
    
    vector<double> dp(cont, -INF);

    dp[idx["pink"]] = 0.0;

    for(int i = 0; i < n; i++){

        int c1 = t[i].c1, c2 = t[i].c2;
        double r = t[i].r;

        dp[c1] = max(dp[c1], dp[c2] + log(r));
    }

    cout << fixed << setprecision(9) << min(10.0, exp(dp[idx["blue"]])) << "\n";

    return 0;   
}
