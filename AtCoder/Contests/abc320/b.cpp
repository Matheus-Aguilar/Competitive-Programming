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

bool palindrome(const string &s, int l, int r){
    for(int i = l, j = r; i < j; i++, j--){
        if(s[i] != s[j]){
            return false;
        }
    }
    return true;
}

int main(){
    optimize;

    int ans = 0;
    string s;

    cin >> s;

    for(int i = 0; i < s.size(); i++){
        for(int j = i; j < s.size(); j++){
            if(palindrome(s, i, j)){
                ans = max(ans, j - i + 1);
            }
        }
    }

    cout << ans << "\n";
    
    return 0;   
}
