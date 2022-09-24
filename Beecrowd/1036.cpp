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

    long double a, b, c, d;
    cin >> a >> b >> c;

    d = b * b - 4 * a * c;

    if(a == 0.0 || d < 0.0)
        cout << "Impossivel calcular\n";
    else{
        long double r1 = (-b + sqrt(d))/(2*a);
        long double r2 = (-b - sqrt(d))/(2*a);
        cout << "R1 = " << fixed << setprecision(5) << r1 << "\n";
        cout << "R2 = " << fixed << setprecision(5) << r2 << "\n";
    }

    return 0;   
}
