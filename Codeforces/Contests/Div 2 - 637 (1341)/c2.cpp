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
        cin >> n;
        vector<int> p(n);
        vector<int> r(n + 1, false);
        
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            p[x - 1] = i + 1;
        }

        bool ans = true;
        int selected = -1;
        for(int i = 0; i < n && ans; i++){
            if(selected == -1 || selected + 1 == p[i]){
                if(p[i] == n || r[p[i] + 1])
                    selected = -1;
                else
                    selected = p[i];
                r[p[i]] = true;
            }
            else{
                ans = false;
            }
        }

        cout << (ans ? "Yes" : "No") << "\n";
    }

    return 0;   
}
