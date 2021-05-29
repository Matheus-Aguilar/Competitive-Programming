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
        int n, i = 1;
        cin >> n;
        vector<int> ans;
        while(n > 0){
            if(n % 10 != 0) 
                ans.push_back((n % 10) * i);
            i *= 10;
            n /= 10;
        }
        cout << ans.size() << "\n";
        for(int a:ans) cout << a << " ";
        cout << "\n";
    }

    return 0;   
}
