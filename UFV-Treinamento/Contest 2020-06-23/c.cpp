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

    int n, cont = 0;
    string s;

    cin >> n >> s;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int x = 0, y = 0;
            for(int k = i; k <= j; k++){
                if(s[k] == 'U') 
                    y++;
                else if(s[k] == 'D') 
                    y--;
                else if(s[k] == 'R') 
                    x++;
                else if(s[k] == 'L') 
                    x--;
            }
            if(x == 0 && y == 0)
                cont++;
        }
    }
    
    cout << cont << "\n";

    return 0;   
}
