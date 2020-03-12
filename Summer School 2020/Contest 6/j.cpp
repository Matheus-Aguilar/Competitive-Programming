#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

long double duration[] = {2, 1, 0.5, 0.25, 0.125, 0.0625};

int m(int x){
    if(x <= 2) return x;
    if(x == 4) return 3;
    if(x == 8) return 4;
    return 5;
}

int main(){
    optimize;

    int n;
    long double ans = 0;

    cin >> n;

    while(n--){
        int x;
        cin >> x;
        ans += duration[m(x)];
    }

    cout << fixed << setprecision(9) << ans << "\n";
}