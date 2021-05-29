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
    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        if(i == 0){
            for(int j = 0; j < 2 * n + 1; j++){
                if(j == 0 || j == n - 1 || j >= n + 1)
                    cout << "*";
                else
                    cout << " ";
            }
        }
        else if(i == n - 1){
            for(int j = 0; j < 2 * n + 1; j++){
                if(j <= n - 1 || j == n + 1 || j == 2 * n)
                    cout << "*";
                else
                    cout << " ";
            }
        }
        else{
            for(int j = 0; j < 2 * n + 1; j++){
                if(j == 0 || j == n - 1 || j == n + 1 || j == 2 * n)
                    cout << "*";
                else
                    cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;   
}

/*

* * ***
* * * *
*** * *

*  * ****
*  * *  *
*  * *  *
**** *  *


*/