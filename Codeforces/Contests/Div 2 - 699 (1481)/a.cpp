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
        int x = 0, y = 0, px, py;
        string s;

        cin >> px >> py >> s;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'U' && y < py){
                y++;
            }
            else if(s[i] == 'R' && x < px){
                x++;
            }
            else if(s[i] == 'D' && y > py){
                y--;
            }
            else if(s[i] == 'L' && x > px){
                x--;
            }
        }

        cout << ((x == px && y == py) ? "YES" : "NO") << "\n";
    }
    
    return 0;   
}
