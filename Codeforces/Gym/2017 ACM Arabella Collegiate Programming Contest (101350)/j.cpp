#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define PI 3.141592653589793

using namespace std;

double deg2rad(ll deg){
    return PI * deg / 180.0;
}

int main(){

    optimize;

    int t;
    cin >> t;

    while(t--){
        ll r, deg;
        cin >> r >> deg;

        double rad = deg2rad(deg);

        cout << fixed << setprecision(6) << r * r * (rad - sin(rad)) / 2.0 << "\n";        
    }

    return 0;
}