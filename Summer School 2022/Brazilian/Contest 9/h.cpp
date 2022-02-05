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

    ifstream in("bugged.in");

    int t;
    in >> t;

    while(t--){
        int n, m;
        in >> n >> m;

        vector<int> x(n), s(m), e(m), aux1, aux2;

        for(int i = 0; i < n; i++)
            in >> x[i];
        for(int i = 0; i < m; i++)
            in >> s[i] >> e[i];
        
        aux1 = s;
        aux2 = e;

        sort(all(aux1));
        sort(all(aux2));

        if(aux1 != aux2){
            cout << -1 << "\n";
        }
        else {

            ll sum = 0;

            for(int i = 0; i < m; i++){
                sum += abs(x[s[i] - 1] - x[e[i] - 1]);
            }

            cout << sum << "\n";
        }
    }
    
    return 0;   
}
