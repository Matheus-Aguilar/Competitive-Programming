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
    
    ifstream in("hello.in");

    int t;
    in >> t;

    while(t--){
        vector<int> a(12);

        for(int i = 0; i < 12; i++)
            in >> a[i];
        
        bool ok = true;

        for(int i = 1; i < 4; i++)
            ok &= (a[i - 1] < a[i]);
        
        for(int i = 0; i < 4; i++){
            for(int j = 4; j < 12; j++){
                ok &= (a[i] < a[j]);
            }
        }

        cout << (ok ? "yes" : "no") << "\n";
    }

    return 0;   
}
