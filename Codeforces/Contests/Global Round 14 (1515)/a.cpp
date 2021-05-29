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
        
        int n, x, sum;
        cin >> n >> x;

        vector<int> w(n);

        for(int i = 0; i < n; i++)
            cin >> w[i];
    
        sum = accumulate(all(w), 0);

        if(sum == x)
            cout << "NO" << "\n";
        else{
            cout << "YES" << "\n";

            sum = 0;

            for(int i = 0; i < n; i++){
                if(sum + w[i] == x)
                    swap(w[i], w[i + 1]);
                sum += w[i];
            }

            for(int i = 0; i < n; i++)
                cout << w[i] << " \n"[i==n-1];
        }
    }

    return 0;   
}
