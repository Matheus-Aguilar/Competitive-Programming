#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define EPS 1e-15

using namespace std;


long double my_sqrt(long double start, long double end, long double x){
    while(abs(end - start) >= EPS){
        long double middle = (start + end)/2.0;

        if(middle * middle > x)
            end = middle;
        else
            start = middle;
    }

    return start;
}

long double my_sqrt(long double x){
    return my_sqrt(0, x, x);
}

int main(){
    optimize;

    long double x;
    cin >> x;

    cout << fixed << setprecision(20) << sqrt(x) << " " << sqrt(x) * sqrt(x) << endl;
    cout << fixed << setprecision(20) << my_sqrt(x) << " " << my_sqrt(x) * my_sqrt(x) << endl;
}