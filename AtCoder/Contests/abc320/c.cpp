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

bool check(string &s, char d){
    return !(all_of(all(s), [d](char x) { return x != d; }));
}

int solve(string s[3], char d, int m){
    if(!check(s[0], d) || !check(s[1], d) || !check(s[2], d))
        return INF;
    
    int t = 0, ok = 0;

    while(ok < 3){
        if(ok == 0){
            if(s[0][t % m] == d)
                ok++;
        } else if(ok == 1){
            if(s[1][t % m] == d)
                ok++;
        } else {
            if(s[2][t % m] == d)
                ok++;
        }
        t++;
    }

    return t - 1;
}

int main(){
    optimize;

    int m;
    string s[3];

    cin >> m;
    cin >> s[0] >> s[1] >> s[2];

    sort(s, s + 3);

    int ans = INF;

    do {
        for(char i = '0'; i <= '9'; i++){
            ans = min(ans, solve(s, i, m));
        }
    } while(next_permutation(s, s + 3));
    
    cout << (ans == INF ? -1 : ans) << "\n";

    return 0;   
}
