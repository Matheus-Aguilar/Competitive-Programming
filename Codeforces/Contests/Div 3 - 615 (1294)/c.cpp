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
        int n, root;
        cin >> n;

        root = (int)sqrt(n);
        vector<int> ans;

        for(int i = 2; i <= root; i++){
            if(n % i == 0){
                ans.push_back(i);
                n /= i;
                if(ans.size() == 2) break;
            }
        }

        if(ans.size() == 2 && n != ans.front() && n != ans.back())
            ans.push_back(n);
        if(ans.size() == 3){
            cout << "YES" << "\n";
            for(int i:ans) cout << i << " ";
            cout << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }

    return 0;   
}
