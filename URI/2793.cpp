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
    
    string s;
    cin >> s;

    int m = 0, f = 0, c = 1;

    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] == 'M')
            m++;
        else
            f++;
        if(m == f){
            c = (2 * c) mod;
            m = f = 0;
        }
    }
    cout << c << "\n";

    return 0;   
}
