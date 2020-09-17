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

    vector<ll> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    if(n == 1){
        cout << 1 << " " << 1 << "\n";
        cout << 1 << "\n";
        cout << 1 << " " << 1 << "\n";
        cout << -1 << "\n";
        cout << 1 << " " << 1 << "\n";
        cout << -a[0] << "\n";
    }
    else{
        
        cout << 1 << " " << n - 1 << "\n";
        for(int i = 0; i < n - 1; i++)
            cout << a[i] * (n - 1) << " \n"[i==n-2];
        
        cout << 2 << " " << n << "\n";
        for(int i = 1; i < n - 1; i++)
            cout << 0 << " ";
        cout << a[n - 1] * (n - 1) << "\n";
        
        cout << 1 << " " << n << "\n";
        for(int i = 0; i < n; i++)
            cout << -a[i] * n << " \n"[i==n-1];
    }

    return 0;   
}
