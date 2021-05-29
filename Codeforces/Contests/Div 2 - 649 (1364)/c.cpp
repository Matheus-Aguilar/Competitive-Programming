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

    vector<int> a(n + 1);
    vector<int> b(n + 1, -1);
    vector<int> r(n + 1, -1);
    set<int> s;

    for(int i = 0; i <= n; i++)
        s.insert(i);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        r[a[i]] = i;
        s.erase(a[i]);
    }

    for(int i = 0; i <= n; i++){
        if(r[i] != -1){
            b[r[i] + 1] = i;
        }
    }

    for(int i = 0; i < n; i++){
        if(b[i] == -1){
            if(!s.empty()){
                b[i] = *s.begin();
                s.erase(s.begin());
            }
            else{
                b[i] = n + 1;
            }
        }
    }

    int pos = 0;
    bool ans = true;
    vector<bool> mex(n + 2, false);

    for(int i = 0; i < n && ans; i++){
        mex[b[i]] = true;
        while(mex[pos] && pos <= n + 1)
            pos++;
        if(pos != a[i])
            ans = false;
    }

    if(!ans)
        cout << -1 << "\n";
    else{
        for(int i = 0; i < n; i++)
            cout << b[i] << " ";
        cout << "\n";
    }

    return 0;   
}
