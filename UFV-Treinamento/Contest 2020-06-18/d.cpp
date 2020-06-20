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
    
    int n, ans = 0;
    cin >> n;

    vector<int> cont(5, 0);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        cont[a]++;
    }

    ans += cont[4];
    ans += cont[3];
    cont[1] = max(0, cont[1] - cont[3]);
    ans += cont[2]/2;
    cont[2] %= 2;
    if(cont[2]){
        ans++;
        cont[1] = max(cont[1] - 2, 0);
    }
    ans += cont[1]/4;
    if(cont[1] % 4 != 0)
        ans++;

    cout << ans << "\n";
    

    return 0;   
}
