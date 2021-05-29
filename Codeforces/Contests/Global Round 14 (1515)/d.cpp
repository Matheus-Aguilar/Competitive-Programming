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
        
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> cl(l);
        vector<int> cr(r);

        for(int i = 0; i < l; i++)
            cin >> cl[i];

        for(int i = 0; i < r; i++)
            cin >> cr[i];

        sort(all(cl));
        sort(all(cr));

        int i = 0, j = 0, rem = 0;
        
        ll ans = 0;

        while(i < l && j < r){
            if(cl[i] == cr[j]){
                cl[i] = cr[j] = INF;
                i++;
                j++;
                rem++;
            }
            else if(cl[i] < cr[j]){
                i++;
            }
            else{
                j++;
            }
        }

        sort(all(cl));
        sort(all(cr));

        l -= rem;
        r -= rem;

        cl.resize(l);
        cr.resize(r);

        if(l > r){

            rem = 0;

            for(int i = 0; i < l - 1 && l - rem > r; i++){
                if(cl[i] == cl[i + 1]){
                    cl[i] = cl[i + 1] = INF;
                    rem += 2;
                    ans++;
                }
            }

            l -= rem;
        }
        else if(r > l){
            
            rem = 0;

            for(int i = 0; i < r - 1 && r - rem > l; i++){
                if(cr[i] == cr[i + 1]){
                    cr[i] = cr[i + 1] = INF;
                    rem += 2;
                    ans++;
                }
            }

            r -= rem;
        }

        int diff = abs(l - r);

        ans += diff / 2;
        ans += min(l, r) + diff / 2;

        cout << ans << "\n";
    }
    
    return 0;   
}
