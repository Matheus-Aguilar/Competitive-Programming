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

int main(){
    optimize;

    int n, m;
    ll fat[21];
    
    fat[0] = 1;
    for(int i = 1; i <= 20; i++)
        fat[i] = i * fat[i - 1];

    while(cin >> n >> m)
        cout << fat[n] + fat[m] << "\n";
    
    return 0;   
}
