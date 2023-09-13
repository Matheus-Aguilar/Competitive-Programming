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
        int n, sum = 0, mini = INF;
        cin >> n;

        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            mini = min(mini, x);
            sum += x;
        }

        if(n % 2 != 0)
            cout << (sum % 2 != 0 ? "Yalalov" : "Shin") << "\n";
        else
            cout << ((sum % 2 != 0 || mini % 2 != 0) ? "Yalalov" : "Shin") << "\n";
    }
    
    return 0;   
}
