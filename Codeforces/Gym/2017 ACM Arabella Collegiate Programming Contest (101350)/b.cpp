#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

int main(){

    optimize;

    int t;
    cin >> t;

    while(t--){
        int a, b;
        cin >> a >> b;
        cout << (a >= b ? "FunkyMonkeys" : "WeWillEatYou") << "\n";
    }

    return 0;
}