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
        string a, b;
        cin >> a >> b;

        int l = 0, r = a.size() - 1, ans = 0;
        bool swapped = false;

        while(l < r){

            bool ok = (a[l] == b[l] && a[r] == b[r]);
            bool okRev = (a[l] == b[r] && a[l] == b[r]);

            if(!ok && !okRev){
                ans = -1;
                break;
            }

            if(!(ok && !swapped) && !(okRev && swapped)){
                ans++;
                swapped = !swapped;
            }

            l++;
            r--;
        }

        if(ans != -1 && a[l] != b[l])
            ans = -1;
        
        cout << ans << "\n";
    }
    
    return 0;   
}
