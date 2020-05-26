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

bool check(string &a, string &b){
    if(a.size() != b.size()) return false;
    for(int i = 0; i < a.size(); i++){
        if(a[i] == '.') continue;
        if(a[i] != b[i]) return false;
    }
    return true;
}

int main(){
    optimize;

    int n;
    string s;
    string names[8] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    cin >> n >> s;

    for(int i = 0; i < 8; i++){
        if(check(s, names[i])){
            cout << names[i] << "\n";
            break;
        }
    }

    return 0;   
}
