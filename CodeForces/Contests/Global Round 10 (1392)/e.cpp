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
    //optimize;

    int n, q, p = 0;
    cin >> n;

    vector<vector<ll>> v(n, vector<ll>(n));
    for(int i = 0; i < n; i++){
        v[i][0] = 0LL;
        for(int j = i - 1, k = 1; j >= 0 && k < n; j--, k++)
            v[j][k] = (v[j + 1][k - 1] ? 0LL : 1LL) * (1LL << p);
        p++;
    }
    for(int i = 1; i < n; i++){
        v[n - 1][i] = 0LL;
        for(int j = n - 2, k = i + 1; j >= 0 && k < n; j--, k++)
            v[j][k] = (v[j + 1][k - 1] ? 0LL : 1LL) * (1LL << p);
        p++;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cout << v[i][j] << " \n"[j==n-1];
    
    cout.flush();

    cin >> q;

    while(q--){
        int x = 1, y = 1, m; 
        ll sum;
        cin >> sum;
        cout << x << " " << y << endl;
        while(x != n || y != n){
            sum /= 2;
            m = sum % 2;
            if(x < n && (bool)v[x][y - 1] == m)
                x++;
            else
                y++;
            sum -= m;
            cout << x << " " << y << endl;
        }
    }

    return 0;   
}
