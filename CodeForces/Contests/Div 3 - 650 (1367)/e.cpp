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

    int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        
        string s;
        cin >> s;
        
        vector<bool> v(n, false);
        vector<int> c(26, 0);
        for(int i = 0; i < n; i++)
            c[(int)(s[i] - 'a')]++;
        for(int i = n; i > 0; i--){
            int cont = 0, sz = 0;
            fill(all(v), false);
            for(int j = 0; !v[j]; j = (j + k) % i){
                cont++;
                v[j] = true;
            }
            for(int j = 0; j < 26; j++)
                sz += (c[j] / cont) * cont;
            if(sz >= i){
                cout << i << "\n";
                break;
            }
        }
    }
    
    return 0;   
}
