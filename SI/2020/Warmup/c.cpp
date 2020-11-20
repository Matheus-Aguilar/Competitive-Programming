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
    getline(cin, s);
    int total = s.size() - count_if(all(s), [](char c){return c == ' ';});
    int vogais = count_if(all(s), [](char c){c = tolower(c); return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';});
    cout << (vogais >= (total + 1)/2 ? "facil" : "dificil") << "\n";

    return 0;   
}
