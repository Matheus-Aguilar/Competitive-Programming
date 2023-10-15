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

unordered_map<int, int> cur, nxt;

int main(){
    optimize;

    int n, k;
    cin >> n >> k;

    vector<int> cur(n), nxt(n, -1);
    unordered_map<int, int> cnt;

    for(int i = 0; i < n; i++){
        cin >> cur[i];
    }

    while(k > 0){
        
        for(int i = 0; i < n; i++)
            cnt[cur[i]]++;
        for(int i = 0; i < n; i++)
            nxt[i] = cnt[cur[i]];
        
        if(cur == nxt)
            break;

        cur.swap(nxt);
        cnt.clear();

        k--;
    }

    for(int i = 0; i < n; i++)
        cout << cur[i] << " \n"[i+1==n];
    
    return 0;   
}
