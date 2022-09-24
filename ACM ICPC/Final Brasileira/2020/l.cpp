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
#define fi first
#define se second

using namespace std;

int main(){
    optimize;
    
    int n, x;
    cin >> n >> x;

    vector<pii> p(n);

    for(int i = 0; i < n; i++){
        cin >> p[i].fi >> p[i].se;
        p[i].se += p[i].fi;
    }

    int pos = -1, best = INF;

    for(int i = 0; i <= 480; i++){

        int sum = 0;

        for(int j = 0; j < n; j++){

            if(p[j].fi == p[j].se){
                
                if((p[j].fi - i) % x == 0){
                    sum++;
                }
                
                continue;
            }
            
            int a = ((p[j].fi - i) / x);
            int b = ((p[j].se - i + x - 1) / x);

            if(p[j].fi < i){ 
                a = -1;
            }

            if(p[j].se < i){
                continue;
            }

            sum += b - a - 1;

            if((p[j].fi - i) % x == 0){
                sum++;
            }

            if((p[j].se - i) % x == 0){
                sum++;
            }
        }

        if(pos == -1 || sum < best){
            pos = i;
            best = sum;
        }
    }

    cout << pos << " " << best << "\n";

    return 0;   
}
