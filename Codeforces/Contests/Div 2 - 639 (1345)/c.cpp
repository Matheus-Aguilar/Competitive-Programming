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
        bool ans = true;
        
        cin >> n;
        vector<int> k(n, 0);
        
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            a += i;
            if(a > 0) 
                a = (a % n);
            else 
                a = (n - ((-a) % n)) % n;
            k[a]++;
        }

        for(int i = 0; i < n && ans; i++)
            ans = (k[i] == 1);
        cout << (ans ? "YES" : "NO") << "\n";
    }

    return 0;   
}
