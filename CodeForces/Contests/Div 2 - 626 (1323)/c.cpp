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
    string s;
    
    cin >> n >> s;

    vector<int> p(n + 1);

    int open = 0, close = 0;

    p[0] = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == ')'){
            close++;
        }
        else{
            open++;
        }

        p[i + 1] = open - close;
    }

    if(p.back() != 0){
        cout << -1 << "\n";
    }
    else{
        ll ans = 0;
        int beg = -1;
        for(int i = 0; i <= n; i++){
            if(p[i] < 0 && beg == -1){
                beg = i;
            }
            else if(p[i] == 0 && beg != -1){
                ans += i - beg + 1;
                beg = -1;
            }
        }

        cout << ans << "\n";
    }

    return 0;   
}
