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

bool solveAB(string &s, string &t, int l, int r){
    
    int cs = 0, ct = 0;

    for(int i = l; i <= r; i++){
        if(s[i] == 'A')
            cs++;
        if(t[i] == 'A')
            ct++;
        if(cs < ct)
            return false;
    }

    return true;
}

bool solve(string &s, string &t, int l, int r){

    if(l > r)
        return true;

    int ca = 0, cb = 0;

    for(int i = l; i <= r; i++){
        if(s[i] == 'A')
            ca--;
        else if(s[i] == 'B')
            cb--;
    }

    for(int i = l; i <= r; i++){
        if(t[i] == 'A')
            ca++;
        else if(t[i] == 'B')
            cb++;
    }

    for(int i = l; i <= r; i++){
        if(s[i] == 'C'){
            if(ca > 0){
                s[i] = 'A';
                ca--;
            } else {
                s[i] = 'B';
                cb--;
            }
        }
    }

    if(ca != 0 || cb != 0)
        return false;

    return solveAB(s, t, l, r);
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){

        int n;
        string x, y;

        cin >> n >> x >> y;
        
        int last = 0;
        bool ok = true;

        for(int i = 0; i < y.size() && ok; i++){
            if(y[i] == 'C' ){
                if(x[i] != 'C' || !solve(x, y, last, i - 1)){
                    ok = false;
                } else {
                    last = i + 1;
                }
            }
        }

        if(ok)
            ok = solve(x, y, last, y.size() - 1);

        cout << (ok ? "Yes" : "No") << "\n";
    }
    
    return 0;   
}
