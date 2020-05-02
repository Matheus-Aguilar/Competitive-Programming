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

    int n, root;
    cin >> n;
    root = sqrt(n);

    for(int i = 1; i <= root; i++)
        if(n % i == 0)
            cout << i << "\n";
    for(int i = root; i >= 1; i--)
        if(n % i == 0 && i != n/i)
            cout << n/i << "\n";
    
    return 0;   
}
