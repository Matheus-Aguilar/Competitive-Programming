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

    vector<int> d(n);

    for(int i = 0; i < n; i++)
        cin >> d[i];
    
    bool ans = true;

    for(int i = 0; i < n - 1 && ans; i++){
        if(abs(d[i] - d[i + 1]) > 1 || d[i] > 2 || d[i + 1] > 2){
            ans = false;
        }
        else{
            d[i + 1] = abs(d[i] - d[i + 1]);
        }
    }

    ans &= (d[n - 1] == 0);
    
    cout << (ans ? "YES" : "NO") << "\n";

    return 0;   
}
