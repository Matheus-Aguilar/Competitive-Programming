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
        int n, princess, prince;
        cin >> n;
        vector<bool> v(n, false);
        vector<int> p(n, -1);
        for(int i = 0; i < n; i++){
            int k;
            cin >> k;
            while(k--){
                int x;
                cin >> x;
                if(!v[x - 1] && p[i] == -1){
                    p[i] = x + 1;
                    v[x - 1] = true;
                }
            }
        }

        if(all_of(all(v), [](bool x){return x;}))
            cout << "OPTIMAL" << "\n";
        else{
            cout << "IMPROVE" << "\n";
            cout << (find(all(p), -1) - p.begin()) + 1 << " ";
            cout << (find(all(v), false) - v.begin()) + 1 << "\n";
        }
    }
    
    return 0;   
}
