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

bool a[100];

int main(){
    optimize;

    int n;
    cin >> n;

    for(int i = 0; i <= 9; i++)
        a[10 * i + 1] = true;
    for(int i = 0; i <= 9; i++)
        a[10 * i + 7] = true;
    for(int i = 0; i <= 9; i++)
        a[10 * i + 9] = true;
    for(int i = 0; i <= 9; i++)
        a[10 + i] = true;
    for(int i = 0; i <= 9; i++)
        a[20 + i] = true;
    for(int i = 0; i <= 9; i++)
        a[70 + i] = true;
    for(int i = 0; i <= 9; i++)
        a[90 + i] = true;

    a[12] = false;

    cout << (!a[n] ? "YES" : "NO") << "\n";
    
    return 0;   
}
