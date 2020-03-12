#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;

    ll n;
    cin >> n;
    cout << (1LL << __builtin_popcountll(n)) << "\n";

    return 0;   
}
