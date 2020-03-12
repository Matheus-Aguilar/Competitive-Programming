#include<bits/stdc++.h>

using namespace std;

double a, b, h, sum = 0, n;

double g(double x){
    return (1.0)/(x+4);
}

double f(double x){
    return g(a + h * x);
}

int main(){
    cin >> a >> b >> n;
    h = (b - a)/n;
    for(int i = 0; i <= n; i++){
        cout << i << " " << f(i) << endl;
        if(i == 0)
            sum += f(i);
        else if(i == n)
            sum += f(i);
        else if(i % 2 != 0)
            sum += 4 * f(i);
        else
            sum += 2 * f(i);
    }

    cout << sum << endl;

    sum *= b - a;
    sum /= 3.0 * n;
    cout << sum << endl;
}