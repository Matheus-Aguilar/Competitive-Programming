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

    vector<ll> a(n + 1), p(n + 1, 0), pm(n + 1, INFLL);

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++)
        p[i] = a[i] + p[i - 1];
    
    for(int i = 1; i <= n; i++)
        pm[i] = min(pm[i - 1], p[i]);  

    bool neg = false;
    ll sm = INFLL;

    vector<int> ans;

    for(int i = n; i > 0; i--){
        sm = min(sm, p[i]);
        if(sm < 0){
            neg = true;
            if(pm[i - 1] >= 0 && a[i] <= sm){
                ans.push_back(i);
            }
        }
    }

    if(!neg)
        cout << "morete chapou: errou conta!" << "\n";
    else if(ans.size() == 0)
        cout << "morete chapou: ficou com saldo negativo!" << "\n";
    else {
        cout << ans.size() << "\n";
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << "\n";
    }

    return 0;   
}
