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
        int c, k, cont = 0;
        bool ok = false;

        cin >> c >> k;

        for(int i = 0; i < c; i++){
            char ch;
            cin >> ch;

            if(ch == '0')
                cont++;
            else
                cont = 0;
            
            if(cont >= k + 1)
                ok = true;
        }

        cout << (ok ? "yes" : "no") << "\n";
    }
    
    return 0;   
}
