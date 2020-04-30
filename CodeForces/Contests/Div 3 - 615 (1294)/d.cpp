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
#define MAXN 500000

using namespace std;

bool mex[MAXN];
int nxt[MAXN];

int main(){
    optimize;
    
    int q, x, i = 0;
    cin >> q >> x;

    for(int i = 0; i < x; i++)
        nxt[i] = i;

    while(q--){

        int y;
        cin >> y;
        
        int r = y % x;
        
        if(nxt[r] < MAXN){
            mex[nxt[r]] = true;
            nxt[r] += x;
        }
        
        while(mex[i]) ++i;
        
        cout << i << "\n";
    }

    return 0;   
}
