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

ll solve(vector<int> &g){

    ll sum = 0;
    int carry = 0;

    for(int i = 0; i < 2 * g.size(); i++){
        int pos = i % g.size();

        if(g[pos] > 0){
            carry += g[pos];
            g[pos] = 0;
        }
        else{
            int give = min(carry, -g[pos]);
            g[pos] += give;
            carry -= give;
        }

        sum += carry;
    }

    return sum;
}

int main(){
    optimize;

    int n, avg = 0;
    cin >> n;

    vector<int> g(n), gr;

    for(int i = 0; i < n; i++){
        cin >> g[i];
        avg += g[i];
    }

    avg /= n;

    for(int i = 0; i < n; i++){
        g[i] -= avg;
    }

    gr = g;
    reverse(all(gr));

    cout << min(solve(g), solve(gr)) << "\n";
    
    return 0;   
}
