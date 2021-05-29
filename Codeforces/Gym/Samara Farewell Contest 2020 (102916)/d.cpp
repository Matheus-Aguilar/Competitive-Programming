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
    vector<long double> p(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(all(a));

    p[0] = 1;

    for(int i = 1; i < n; i++){
        
        p[i] = 0;
        long double np = 1, prod = 1;

        for(int j = 0; j < i; j++){
            
            
            
            np *= n - 2 * j - 1;
            np /= n - 2 * j;
        }
    }
    
    return 0;   
}
