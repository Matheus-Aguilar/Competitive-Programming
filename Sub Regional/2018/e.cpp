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

bool check(string &s, string &w, int k){
    for(int i = 0, j = k; i < w.size(); i++, j++){
        if(w[i] == s[j]){
            return true;
        }
    }
    return false;
}

int main(){
    optimize;

    int ans = 0;
    string s, w;
    cin >> s >> w;
    
    for(int i = 0; i <= s.size() - w.size(); i++)
        if(!check(s, w, i)) 
            ans++;
    cout << ans << "\n";
    return 0;   
}
