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
        int n, k;
        cin >> n >> k;
        
        if(k % 2 == 0 && n % 2 != 0){
            cout << "NO" << "\n"; 
        }
        else if(k % 2 != 0 && n % 2 == 0){
            if(2 * k > n){
                cout << "NO" << "\n";
            }
            else{
                cout << "YES" << "\n";
                cout << n - 2 * k + 2 << " ";
                while(--k) cout << 2 << " ";
                cout << "\n";
            }
        }
        else if(k % 2 != 0 && n % 2 != 0){
            if(k > n){
                cout << "NO" << "\n";
            }
            else{
                cout << "YES" << "\n";
                cout << n - k + 1 << " ";
                while(--k) cout << 1 << " ";
                cout << "\n";
            }
        }
        else{
            if(k > n){
                cout << "NO" << "\n";
            }
            else{
                cout << "YES" << "\n";
                cout << n - k + 1 << " ";
                while(--k) cout << 1 << " ";
                cout << "\n";
            }
        }
    }
    return 0;   
}
