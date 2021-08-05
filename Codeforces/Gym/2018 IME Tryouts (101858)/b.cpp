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

    string s, ans;
    cin >> s;

    int cont = 0;

    for(int i = 0; i < s.size(); i++){
        
        if(i == 0 || s[i] != s[i - 1]){
            cont = 1;
        }
        else{
            cont++;
        }
        
        if(cont == 3){
            if(s[i] == 'C'){
                ans += 'P';
            }
            else{
                ans += 'T';
            }

            cont = 0;
            s[i] = 'X';
        }
        else{
            if(s[i] == 'C'){
                ans += 'B';
            }
            else{
                ans += 'D';
            }
        }
    }

    cout << ans << "\n";
    
    return 0;   
}
