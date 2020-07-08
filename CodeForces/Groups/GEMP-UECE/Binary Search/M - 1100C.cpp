#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>
#define PI 3.14159265358979323846

using namespace std;

long double toRad(long double deg){
    return (deg * PI)/180.0;
}

int main(){
    optimize;
    long double n, r;
    cin >> n >> r;
    cout << fixed << setprecision(9) << (r * sin(toRad(180.0/n)))/(1 - sin(toRad(180.0/n))) << "\n";
    return 0;   
}
