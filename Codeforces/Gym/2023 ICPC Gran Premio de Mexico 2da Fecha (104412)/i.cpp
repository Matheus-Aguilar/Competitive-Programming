#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long

using namespace std;

int main(){

    optimize;

    ll n, m, k;
    cin >> n >> m >> k;

    cout << (n >= m * k ? "Iron fist Ketil" : "King Canute") << "\n";

    return 0;
}