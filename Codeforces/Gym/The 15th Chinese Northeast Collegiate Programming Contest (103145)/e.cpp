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
        ll p, goal;
        int r;

        cin >> p;

        p *= 6;
        goal = p;
        r = sqrt(p);
        
        vector<ll> div, ans;

        for(int i = 1; i <= r; i++){
            if(p % i == 0){
                div.push_back(i);
                if(i != 1 && i != p / i) div.push_back(p / i);
            }
        }

        sort(all(div));
        reverse(all(div));

        for(int i = 0; i < div.size(); i++){
            if(goal >= div[i]){
                goal -= div[i];
                ans.push_back(div[i]);
            }
        }

        if(goal != 0) assert(false);

        cout << p << " " << ans.size() << "\n";

        for(int i = (int)ans.size() - 1; i >= 0; i--){
            cout << ans[i] << " \n"[i==0];
        }
    }

    return 0;   
}
