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
        
        int n;
        bool ok = false;

        cin >> n;

        vector<int> a(n + 1);
        vector<int> x(n + 1, 0);
        
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            x[i] = x[i - 1] ^ a[i];
        }

        //Caso 2
        for(int i = 1; i < n; i++){
            if(x[i] == (x[n] ^ x[i]))
                ok = true;
        }

        //Caso 3
        for(int i = 1; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(x[i] == (x[j] ^ x[i]) && x[i] == (x[n] ^ x[j]))
                    ok = true;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
    
    return 0;   
}
