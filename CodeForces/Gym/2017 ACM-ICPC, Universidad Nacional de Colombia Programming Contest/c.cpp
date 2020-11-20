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

struct Line{
    ll x, y, z;
    
    Line(ll _x = -1, ll _y = -1, ll _z = -1) : x(_x), y(_y), z(_z){}
    
    Line operator-(const Line &l) const{ 
        return Line(x - l.x, y - l.y, z - l.z); 
    }

    bool operator<(const Line &l) const{
        if(x != l.x) return x < l.x;
        if(y != l.y) return y < l.y;
        return z < l.z;
    }
    
    void adjust(){
        ll mdc = __gcd(__gcd(abs(x), abs(y)), abs(z));

        if(mdc == 0) 
            return;

        x /= mdc;
        y /= mdc;
        z /= mdc;

        if(x < 0 || (x == 0 || y < 0) || (x == 0 || y == 0 || z < 0)){
            x *= -1;
            y *= -1;
            z *= -1;
        }
    }
};

int main(){
    optimize;

    int n;
    cin >> n;

    Line origin;
    set<Line> s;

    cin >> origin.x >> origin.y >> origin.z;

    while(--n){
        Line planet;
        cin >> planet.x >> planet.y >> planet.z;
        planet = planet - origin;
        planet.adjust();
        s.insert(planet);
    }

    cout << s.size() << "\n";

    return 0;   
}
