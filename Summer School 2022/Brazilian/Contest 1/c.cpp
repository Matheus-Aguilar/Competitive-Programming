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
#define MAXN 100100

using namespace std;

int n, c, x[MAXN];

bool check(int d) {

    if(c == 1) 
        return true;

    int cur = 0, nxt = 0, cont = 1;

    while(nxt < n) {
        if(x[nxt] - x[cur] >= d){
            cur = nxt;
            cont++;
        
            if(cont == c) {
                return true;
            }
        }
        nxt++;
    }

    return false;
}

int binSearch(int l, int r) {
    while(l < r) {
        int m = l + (r - l) / 2;

        if(check(m))
            l = m + 1;
        else
            r = m;
    }
    return l - 1;
}

int main(){
    optimize;
    
    int t;
    cin >> t;

    while(t--){
        cin >> n >> c;
        
        for(int i = 0; i < n; i++)
            cin >> x[i];

        sort(x, x + n);

        cout << binSearch(1, INF) << "\n";
    }

    return 0;   
}
