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
        int n, cont = 0, ans = 0, first = -1;
        cin >> n;

        string s;
        cin >> s;

        for(int i = 1; i < n; i++){
            if(s[i - 1] != s[i]){
                if(first == -1)
                    first = i;
                else
                    ans += cont/3;
                cont = 0;
            }
            cont++;
        }

        if(first == -1)
            ans += (n + 2)/3;
        else if(s[0] == s[n - 1]){
            ans += (first + cont)/3;
        }
        else{
            ans += first/3;
            ans += cont/3;
        }

        cout << ans << "\n";
    }
    
    return 0;   
}
