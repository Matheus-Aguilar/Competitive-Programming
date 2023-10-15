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

    map<ll, int> cnt;

    for(int i = 0; i < n; i++){
        ll s, c;
        cin >> s >> c;
        cnt[s] = c; 
    }
    
    auto it = cnt.begin();

    while(it != cnt.end()){
        
        ll s = it->first;
        ll c = it->second;

        if(c > 1){
            cnt[2 * s] += c / 2;
            cnt[s] = c % 2;
        }
            
        it = cnt.find(s);
        it++;
    }

    int ans = 0;
    it = cnt.begin();

    while(it != cnt.end()){
        if(it->second > 0)
            ans++;
        it++;
    }

    cout << ans << "\n";

    return 0;   
}
