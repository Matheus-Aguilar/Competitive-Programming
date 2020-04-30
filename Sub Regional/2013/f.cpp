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

    int n;
    while(cin >> n){
        int sum = 0, ans = 0;
        vector<int> x(n);
        vector<int> p(n);
        
        for(int i = 0; i < n; i++){
            p[i] = sum;
            cin >> x[i];
            sum += x[i];
        }

        if(sum % 3 != 0){
            cout << 0 << "\n";
        }
        else{
            sum /= 3;
            for(int i = 0; p[i] < sum; i++)
                if(binary_search(all(p), p[i] + sum) && binary_search(all(p), p[i] + 2 * sum))
                    ans++;
            cout << ans << "\n";
        }
    }
    return 0;   
}
