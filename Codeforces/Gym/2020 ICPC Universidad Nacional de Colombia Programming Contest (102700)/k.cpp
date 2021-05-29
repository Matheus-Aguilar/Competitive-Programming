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

void split(pair<string, string> &s){
    int i = 0;
    while(i < s.first.size() && s.first[i] >= 'a' && s.first[i] <= 'z') 
        i++;
    s.second = s.first.substr(i, s.first.size() - i);
    s.first = s.first.substr(0, i);
}

int main(){
    optimize;

    pair<string, string> s1, s2;
    cin >> s1.first >> s2.first;

    split(s1);
    split(s2);

    string zeroes = "";

    while(zeroes.size() + s1.second.size() < s2.second.size())
        zeroes += "0";

    s1.second = zeroes + s1.second;

    zeroes = "";

    while(zeroes.size() + s2.second.size() < s1.second.size())
        zeroes += "0";

    s2.second = zeroes + s2.second;

    cout << (s1 < s2 ? '<': ( s1 > s2 ? '>': '=') ) << "\n";

    return 0;   
}
