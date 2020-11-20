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

    int n, l, p;
    
    while(cin >> n >> l >> p){

        vector<int> r(l + 1, INF);
        vector<int> t(l + 1, 0);
    
        for(int i = 1; i <= l; i++){
            t[i] = min(n / i, p);
            r[i] = max(n - i * t[i], 0);
        }

        int best = *min_element(all(r));

        for(int i = 1; i <= l; i++){
            if(r[i] == best){
                cout << i << " " << r[i] << "\n";
                break;
            }
        }
    }
    
    return 0;   
}
