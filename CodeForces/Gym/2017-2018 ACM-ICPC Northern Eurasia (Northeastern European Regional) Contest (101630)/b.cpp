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

//a = eixo x, b = eixo y, c = eixo z

bool check(int a, int b, int c, int w, int h){
    return (b + 2 * c <= h && 2 * a + 2 * c <= w) || (b + c <= h && 3 * a + b + c <= w);
}

int main(){
    optimize;

    int a, b, c, w, h;
    cin >> a >> b >> c >> w >> h;

    if(check(a, b, c, w, h))
        cout << "Yes" << "\n";
    else if(check(a, c, b, w, h))
        cout << "Yes" << "\n";
    else if(check(b, a, c, w, h))
        cout << "Yes" << "\n";
    else if(check(b, c, a, w, h))
        cout << "Yes" << "\n";
    else if(check(c, a, b, w, h))
        cout << "Yes" << "\n";
    else if(check(c, b, a, w, h))
        cout << "Yes" << "\n";
    else if(check(a, b, c, h, w))
        cout << "Yes" << "\n";
    else if(check(a, c, b, h, w))
        cout << "Yes" << "\n";
    else if(check(b, a, c, h, w))
        cout << "Yes" << "\n";
    else if(check(b, c, a, h, w))
        cout << "Yes" << "\n";
    else if(check(c, a, b, h, w))
        cout << "Yes" << "\n";
    else if(check(c, b, a, h, w))
        cout << "Yes" << "\n";
    else
        cout << "No" << "\n";
    
    return 0;   
}
