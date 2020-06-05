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
    vector<int> g(n);
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> g[i];
    iota(all(v), 0);

    int diff = n - g[0];
    for(int i = 0; i < n; i++){
        if(i & 1){
            g[i] = (g[i] - diff + n) % n;
        }
        else{
            g[i] = (g[i] + diff) % n;
        }
    }
    
    cout << (g == v ? "Yes" : "No") << "\n";

    return 0;   
}
