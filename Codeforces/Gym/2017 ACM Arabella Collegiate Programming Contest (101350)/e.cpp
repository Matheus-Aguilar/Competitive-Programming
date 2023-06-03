#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

int main(){

    optimize;

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        if(n == 2 || n == 3)
            cout << "second" << "\n";
        else
            cout << "first" << "\n";
    }

    return 0;
}