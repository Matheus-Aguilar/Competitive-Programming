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

int s[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n, sum = 0;
        string num, ans = "";

        cin >> n >> num;

        for(int i = 0; i < num.size(); i++){
            sum += s[num[i] - '0'];
        }

        for(int i = 0; i < n; i++){
            for(int j = 9; j >= 0; j--){
                if(sum - s[j] >= 2 * (n - i - 1) && sum - s[j] <= 7 * (n - i - 1)){
                    ans += ('0' + j);
                    sum -= s[j];
                    break;
                }
            }
        }

        cout << ans << "\n";
    }
    
    return 0;   
}
