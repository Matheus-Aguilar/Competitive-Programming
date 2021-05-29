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
    
    int n, k;
    string s;
    ll ans = 0, cont = 0;
    bool l[26];
    ms(l, 0);

    cin >> n >> k;

    cin >> s;
    while(k--){
        char c;
        cin >> c;
        l[(int)(c - 'a')] = true;
    }

    for(int i = 0; i < n; i++){
        if(l[(int)(s[i] - 'a')]){
            cont++;
        }
        else{
            ans += (cont * (cont + 1))/2;
            cont = 0;
        }
    }

    ans += (cont * (cont + 1))/2;
    cout << ans << "\n";

    return 0;   
}
