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

    int t;
    cin >> t;
    while(t--){
        ll n;
        int m;
        cin >> n >> m;

        vector<int> a(m);
        vector<int> p(64, 0);
        for(int i = 0; i < m; i++){
            cin >> a[i];
            p[__builtin_ctz(a[i])]++;
        }

        bool ans = true;
        int i = 0, div = 0;
        while(i < 63 && ans){
            if(n & (1LL << i)){
                if(p[i]){
                    p[i]--;
                }
                else{
                    int j = i;
                    while(j < 63 && !p[j]) j++;
                    if(j == 63) 
                        ans = false;
                    else{
                        while(j != i){
                            p[j]--;
                            p[j - 1] += 2;
                            j--;
                            div++;
                        }
                        p[i]--;
                    }
                }
            }
            p[i + 1] += p[i]/2;
            i++;
        }
        cout << (ans ? div : -1) << "\n";
    }

    return 0;   
}
