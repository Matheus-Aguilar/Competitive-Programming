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
#define MAXN 1100

using namespace std;

int main(){
    optimize;

    int n, nu = 0;
    bool ans = true;

    cin >> n;

    vector<int> a(n);
    vector<int> c(MAXN, 0);
    vector<int> u;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    for(int i = 0; i < n && ans; i++){
        if(a[i] > 0)
            c[a[i]]++;
        else if(a[i] == 0)
            nu++;
        else{
            if(c[-a[i]] > 0)
                c[-a[i]]--;
            else if(nu > 0){
                nu--;
                u.push_back(-a[i]);
            }
            else
                ans = false;
        }
    }

    while(ans && nu--)
        u.push_back(1);

    cout << (ans ? "Yes" : "No") << "\n";

    if(ans){
        for(int i = 0; i < u.size(); i++)
            cout << u[i] << " \n"[i==u.size()-1];
    }

    return 0;   
}
