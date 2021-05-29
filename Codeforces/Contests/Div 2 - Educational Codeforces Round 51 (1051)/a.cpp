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

    int tests;
    cin >> tests;
    while(tests--){
        string s, sub;
        cin >> s;
        
        int up = -1, low = -1, dig = -1;
        int cUp = 0, cLow = 0, cDig = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(isupper(s[i])) up = i, cUp++;
            else if(islower(s[i])) low = i, cLow++;
            else dig = i, cDig++;
        }

        if(up == -1) sub.push_back('A');
        if(low == -1) sub.push_back('a');
        if(dig == -1) sub.push_back('1');

        if(sub.size() == 2){
            s[0] = sub[0];
            s[1] = sub[1];
        }
        else if(sub.size() == 1){
            if(cUp > 1) s[up] = sub[0];
            else if(cLow > 1) s[low] = sub[0];
            else s[dig] = sub[0];
        }

        cout << s << "\n";
    }
    
    return 0;   
}
