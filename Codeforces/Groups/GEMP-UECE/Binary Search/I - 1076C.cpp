#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;

    int t;
    cin >> t;

    long double a, d;
    
    while(t--){

        cin >> d;

        if(d * d - 4 * d < 0){
            cout << "N" << "\n";
            continue;
        }
        
        a = (d + sqrt(d * d - 4 * d))/2;

        if(d - a < 0){
            cout << "N" << "\n";
        }
        else{
            cout << "Y" << " " << fixed << setprecision(9) << a << " " << d - a << "\n";;
        }
    }
    
    return 0;   
}
