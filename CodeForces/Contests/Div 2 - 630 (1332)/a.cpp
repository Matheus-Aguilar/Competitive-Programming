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
    
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;

        x += (b - a);
        y += (d - c);

        if((x1 == x2 && x1 == x && (a || b)) || (y1 == y2 && y1 == y && (c || d)))
            cout << "NO" << "\n";
        else if(x >= x1 && x <= x2 && y >= y1 && y <= y2)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }

    return 0;   
}
