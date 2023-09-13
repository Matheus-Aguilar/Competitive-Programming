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

int k;
string s;
vector<string> str;

int main(){
    optimize;
    
    cin >> s >> k;

    str.assign(k, "");

    for(int i = 0; i < s.size(); i++){
        str[i % k] += s[i];
    }

    for(int i = 0; i < k; i++){
        sort(all(str[i]));
    }

    for(int i = 0; i < s.size(); i++){
        cout << str[i % k][i / k];
    }

    cout << "\n";

    return 0;   
}
