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

    int cont = 0;

    string s, s1, s2;
    getline(cin, s);

    for(int i = 0, j = s.size() - 1; i < s.size() && j >= 0; i++, j--){
        if(s[i] != ' ')
            s1 += tolower(s[i]);
        if(s[j] != ' ')
            s2 += tolower(s[j]);
    }

    for(int i = 0; i < s1.size(); i++)
        cont += (s1[i] != s2[i]);

    cout << (cont > 2 ? "NO" : "YES") << "\n";
    
    return 0;   
}
