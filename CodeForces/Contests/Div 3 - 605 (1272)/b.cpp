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
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        int l = 0, r = 0, u = 0, d = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'L') l++;
            else if(s[i] == 'R') r++;
            else if(s[i] == 'U') u++;
            else d++;
        } 

        l = min(l, r);
        r = min(l, r);
        u = min(u, d);
        d = min(u, d);

        if(l == 0 && u == 0){
            cout << 0 << "\n";
        }
        else if(u == 0){
            cout << 2 << "\n" << "LR" << "\n";
        }
        else if(l == 0){
            cout << 2 << "\n" << "UD" << "\n";
        }
        else{
            cout << l + r + u + d << "\n";
            for(int i = 0; i < l; i++)
                cout << "L";
            for(int i = 0; i < u; i++)
                cout << "U";
            for(int i = 0; i < r; i++)
                cout << "R";
            for(int i = 0; i < d; i++)
                cout << "D";
            cout << "\n";
        }
    }
    
    return 0;   
}
