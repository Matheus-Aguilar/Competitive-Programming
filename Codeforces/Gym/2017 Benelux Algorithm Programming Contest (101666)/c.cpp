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
    set<ll> ans;

    cin >> n;
    vector<ll> a1(n), a2;

    for(int i = 0; i < n; i++){
        cin >> a1[i];
    }

    while(!a1.empty()){

        for(int i = 0; i < a1.size(); i++)
            ans.insert(a1[i]);
        
        for(int i = 0; i < a1.size() - 1; i++){
            
            ll g = __gcd(a1[i], a1[i + 1]);

            if(a2.empty() || a2.back() != g)
                a2.push_back(g);
        }

        a1.swap(a2);
        a2.clear();
    }

    cout << ans.size() << "\n";
    
    return 0;   
}
