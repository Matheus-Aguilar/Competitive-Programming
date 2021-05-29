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

ll cont = 0;
string s;

bool vogal(char c){
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

ll solve(int l, int r, bool rev){
    
    cont++;

    if(l == r)
        return 1;

    if(!rev){
        char c1 = s[l], c2 = s[r];

        if(vogal(c1)){
            if(vogal(c2)){
                int aux = 0;
                
                aux += solve(l + 1, r, !rev);

                return aux;
            }
            else{
                
                int aux = 0;
            
                aux += solve(l, r - 1, rev);
                aux += solve(l + 1, r, !rev);
            
                return aux;
            }
        }
        else{
            if(vogal(c2)){
                return 0;
            }
            else{
                int aux = 0;

                aux += solve(l, r - 1, rev);

                return aux;
            }
        }
    }
    else{
        char c1 = s[r], c2 = s[l];

        if(vogal(c1)){
            if(vogal(c2)){
                int aux = 0;
                
                aux += solve(l, r - 1, !rev);

                return aux;
            }
            else{
                
                int aux = 0;
            
                aux += solve(l + 1, r, rev);
                aux += solve(l, r - 1, !rev);
            
                return aux;
            }
        }
        else{
            if(vogal(c2)){
                return 0;
            }
            else{
                int aux = 0;
                
                aux += solve(l + 1, r, rev);

                return aux;
            }
        }
    }
}

int main(){
    optimize;

    cin >> s;
    cout << solve(0, s.size() - 1, false) << "\n";
    cout << "Calls: " << cont << "\n";
    
    return 0;   
}
