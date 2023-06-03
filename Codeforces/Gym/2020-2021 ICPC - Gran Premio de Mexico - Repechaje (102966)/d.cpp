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
#define MAXN 1000100

using namespace std;

int fac[MAXN];

void sieve(ll limit){
    for(ll i = 2; i < limit; i++){
        if(!fac[i]){
            fac[i] = i;
            for(ll j = i * i; j < limit; j += i){
                if(!fac[j])
                    fac[j] = i;
            }
        }
    }
}

int main(){
    optimize;

    sieve(MAXN);

    int t;
    cin >> t;

    while(t--){
        
        int k;
        vector<int> ans;

        cin >> k;

        k += 2;

        while(k > 1){
            
            int f = fac[k];
            
            if(f > 2)
                ans.push_back(f);

            while(k % f == 0)
                k /= f;
        }

        if(ans.empty())
            cout << -1 << "\n";
        else{
            for(int i = 0; i < ans.size(); i++){
                cout << ans[i] << " \n"[i+1==ans.size()];
            }
        }
    }
    
    return 0;   
}
