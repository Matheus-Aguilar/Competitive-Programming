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
        int n, x, y;
        cin >> n >> x >> y;

        vector<int> v;
        
        for(int i = 1; i <= y - x && n; i++){
            if(x % i == y % i && (y - x)/i <= n - 1){
                for(int j = x; j <= y; j += i, n--)
                    v.push_back(j);
                for(int j = x - i; j > 0 && n; j -= i, n--)
                    v.push_back(j);
                for(int j = y + i; n; j += i, n--)
                    v.push_back(j);
            }
        }

        for(int i = 0; i < v.size(); i++)
            cout << v[i] << " \n"[i==v.size()-1];
    }

    return 0;   
}
