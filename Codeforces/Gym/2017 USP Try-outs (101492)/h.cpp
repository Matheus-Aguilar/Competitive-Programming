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

    int x0, y0, xd, yd;
    char d, d1, d2;

    cin >> x0 >> y0 >> d >> xd >> yd;
    
    vector<pair<char, int>> c;

    d1 = (x0 < xd ? 'E' : x0 > xd ? 'O' : 'X');
    d2 = (y0 < yd ? 'N' : y0 > yd ? 'S' : 'X');

    while(x0 != xd || y0 != yd){
        if(d == d1 && x0 != xd){
            c.emplace_back('A', abs(xd - x0));
            x0 = xd;
        }
        else if(d == d2 && y0 != yd){
            c.emplace_back('A', abs(yd - y0));
            y0 = yd;
        }
        else{
            d = (d == 'N' ? 'E' : (d == 'E' ? 'S' : (d == 'S' ? 'O' : 'N')));
            c.emplace_back('D', -1);
        }
    }

    cout << c.size() << "\n";

    for(int i = 0; i < c.size(); i++){
        if(c[i].first == 'A')
            cout << c[i].first << " " << c[i].second << "\n";
        else
            cout << c[i].first << "\n";
    }

    return 0;   
}
