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

int base10(char c){
    if('0' <= c && c <= '9')
        return (int)(c - '0');
    if('A' <= c && c <= 'Z')
        return (int)(c - 'A') + 10;
    return (int)(c - 'a') + 36;
}

void solve(string &s, int &sum, int &base){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '-')
            continue;
        int val = base10(s[i]);
        sum += val;
        base = max(base, val);
    }
}

int main(){
    optimize;

    string s;
    while(cin >> s){
        int base = 0, sum = 0;
        solve(s, sum, base);

        if(base == 0){
            cout << 2 << "\n";
            continue;
        }

        while(sum % base != 0 && base < 61)
            base++;

        if(sum % base == 0)
            cout << base + 1 << "\n";
        else
            cout << "such number is impossible!" << "\n";
    }
    
    return 0;   
}
