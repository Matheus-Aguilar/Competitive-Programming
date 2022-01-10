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

int n, k, cont = 0;
ll cod[30];

map<string, int> nut;

int main(){
    optimize;

    ms(cod, 0);

    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        int ni;
        cin >> ni;

        for(int j = 0; j < ni; j++){
            
            cin >> s;

            if(nut.find(s) == nut.end()){
                nut[s] = cont++;
            }

            cod[i] |= (1LL << nut[s]);
        }
    }

    int ans = INF;

    for(int i = 0; i < (1 << n); i++){
        
        int num = 0;
        ll h = 0;
        
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                num++;
                h |= cod[j];
            }
        }

        if(__builtin_popcountll(h) >= k){
            ans = min(ans, num);
        }
    }

    cout << (ans == INF ? -1 : ans) << "\n";

    return 0;   
}
