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

bool square(int n){

    int i = 1;

    while(i <= n / i){
        if(n / i == i && n % i == 0)
            return true;
        i++;
    }

    return false;
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        
        int n;
        cin >> n;

        if(n % 2 != 0)
            cout << "NO" << "\n";
        else{
            
            n /= 2;

            if(square(n))
                cout << "YES" << "\n";
            else{
                if(n % 2 != 0)
                    cout << "NO" << "\n";
                else{
                    n /= 2;

                    if(square(n))
                        cout << "YES" << "\n";
                    else
                        cout << "NO" << "\n";
                }
            }
        }
    }
    
    return 0;   
}
