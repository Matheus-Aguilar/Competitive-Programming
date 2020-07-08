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

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n == 1)
            cout << -1 << "\n";
        else{
            if(5 * (n - 1) % 3 == 0){
                for(int i = 0; i < n - 2; i++)
                    cout << 5;
                cout << 33 << "\n";
            }
            else{
                for(int i = 0; i < n - 1; i++)
                    cout << 5;
                cout << 3 << "\n";
            }
        }
    }
    
    return 0;   
}
