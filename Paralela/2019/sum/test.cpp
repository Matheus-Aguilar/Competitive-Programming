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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char **argv){
    optimize;
    
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    cout << n << "\n" << k << "\n";

    for(int i = 0; i < n; i++)
        cout << rng() % 100 << " \n"[i==n-1];

    return 0;   
}