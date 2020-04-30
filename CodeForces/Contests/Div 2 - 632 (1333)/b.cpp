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

        int n, plus = 0, minus = 0;
        bool ans = true;

        cin >> n;
        
        vector<int> a(n);
        vector<int> b(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] > 0) plus++;
            else if(a[i] < 0) minus++;
        }

        for(int i = 0; i < n; i++){
            cin >> b[i];
        }

        for(int i = n - 1; i >= 0 && ans; i--){
            if(a[i] > 0) plus--;
            else if(a[i] < 0) minus--;

            if(b[i] > a[i] && !plus) ans =  false;
            if(b[i] < a[i] && !minus) ans = false;
        }

        cout << (ans ? "YES" : "NO") << "\n";
    }

    return 0;   
}
