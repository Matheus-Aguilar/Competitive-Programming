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

    int n, sum = 0, cont = 0, ans = 0;
    cin >> n;

    vector<int> d(n);

    for(int i = 0; i < n; i++){
        cin >> d[i];
    }

    for(int i = 1, j = 0; i <= 365; i++){
        
        if(cont * i - sum >= 20){
            cont = 0;
            sum = 0;
            ans++;
        }
        
        if(d[j] == i){
            sum += d[j];
            cont++;
            j++;
        }
    }

    if(cont > 0){
        ans++;
    }

    cout << ans << "\n";
    
    return 0;   
}
