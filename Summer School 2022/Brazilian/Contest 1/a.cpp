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

bool check(int y) {
    
    string s = to_string(y);
    sort(all(s));

    for(int i = 1; i < s.size(); i++){
        if(s[i - 1] == s[i]){
            return false;
        }
    }

    return true;
}

int main(){
    optimize;
    
    int y;
    cin >> y;

    do {
        y++;
    } while(!check(y));

    cout << y << "\n";

    return 0;   
}
