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

    int n, m;
    while(cin >> n >> m && n && m){
        
        vector<pii> c(n);

        for(int i = 0; i < n; i++){
            int s, d;
            cin >> s >> d >> c[i].first >> c[i].second;
            c[i].second += c[i].first - 1;
        }

        while(m--){
            
            int s, d, cont = 0;
            cin >> s >> d;
            d += s - 1;

            for(int i = 0; i < n; i++)
                if(d >= c[i].first && s <= c[i].second)
                    cont++;

            cout << cont << "\n";
        }
    }
    
    return 0;   
}
