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

    string s[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    int n, d = 0, y = 1868;
    cin >> n;

    for(int i = 1; i <= n; i++){
        if(y % 4 != 0)
            d++;
        else{
            if(y % 100 == 0){
                if(y % 400 == 0)
                    d += 2;
                else
                    d++;
            }
            else
                d += 2;
        }
        y++;
        d %= 7;
    }

    cout << s[d] << "\n";
    
    return 0;   
}
