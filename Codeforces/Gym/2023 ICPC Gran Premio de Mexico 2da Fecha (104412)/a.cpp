#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

int main(){

    optimize;

    int n, ans = 0;
    cin >> n;

    string s;
    cin >> s;

    for(int i = 0; i < n; i++){
        char x = s[i];
        if(x != '0' && x != '6' && x != '8')
            ans++;
    }

    cout << ans << "\n";

    return 0;
}