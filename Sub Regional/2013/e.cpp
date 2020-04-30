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
    
    int n, r;
    while(cin >> n >> r){
        vector<bool> v(n, false);
        for(int i = 0; i < r; i++){
            int x;
            cin >> x;
            v[x - 1] = true;
        }
        bool ok = true;
        for(int i = 0; i < n; i++){
            if(!v[i]){
                ok = false;
                cout << i + 1 << ' '; 
            }
        }
        if(ok) 
            cout << '*' << '\n';
        else 
            cout << '\n';
    }

    return 0;   
}
