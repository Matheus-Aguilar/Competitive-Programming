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

/*
tant = h / (1/2) = 2h
tant = x / (b / 2) = 2x / b

=> 2x / b = 2h => b = 2x / 2h = x / h

((x / h) * x) / 2

AT = h / 2
Ax = (x^2) / 2h

Cada triângulo deve ter área h / 2n

Logo, o primeiro corte deve ser em (x^2) / 2h = h / 2n => x^2 / h = h / n => x^2 = h^2 / n => x = h / sqrt(n)

Ax = ((x + xi) / h) * ((x - xi) / 2) = (x^2 - xi^2) / 2h

(x^2 - xi^2) / 2h = h / 2n => (x^2 - xi^2) / h = h / n => x^2 - xi^2 = h^2 / n => x = sqrt(h^2 / n + xi^2) 
*/

int main(){
    optimize;

    ll n, h;
    cin >> n >> h;

    double x = 0.0;

    for(int i = 0; i < n - 1; i++){
        x = sqrt((h * h) / (n * 1.0) + x * x);
        cout << fixed << setprecision(12) << x << " \n"[i==n-2];
    }
    
    return 0;   
}
