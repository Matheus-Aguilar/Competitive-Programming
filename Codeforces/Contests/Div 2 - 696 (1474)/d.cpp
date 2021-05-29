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
        bool ok;

        cin >> n;

        vector<ll> a(n + 2, 0), p(n + 2, 0), s(n + 2, 0);
    

        for(int i = 1; i <= n; i++)
            cin >> a[i];
        
        ok = true;

        for(int i = 1; i <= n + 1; i++){
            if(p[i - 1] == -1 || p[i - 1] > a[i]){
                p[i] = -1; //not possible
                ok = false;
            }
            else{
                p[i] = a[i] - p[i - 1];
            }
        }

        if(ok){
            cout << "YES" << "\n";
            continue;
        }

        ok = true;

        for(int i = n; i >= 0; i--){
            if(s[i + 1] == -1 || s[i + 1] > a[i]){
                s[i] = -1; //not possible
                ok = false;
            }
            else{
                s[i] = a[i] - s[i + 1];
            }
        }

        if(ok){
            cout << "YES" << "\n";
            continue;
        }

        for(int i = 1; i < n && !ok; i++){

            if(p[i - 1] == -1 || s[i + 2] == -1)
                continue;
                
            if(p[i - 1] <= a[i + 1]){
                if(a[i + 1] - p[i - 1] <= a[i]){
                    if(a[i] - (a[i + 1] - p[i - 1]) <= s[i + 2]){
                        if(s[i + 2] - (a[i] - (a[i + 1] - p[i - 1])) == 0){
                            ok = true;
                        }
                    }
                }
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
    
    return 0;   
}
