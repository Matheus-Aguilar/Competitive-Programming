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

        int n;
        cin >> n;

        vector<int> a(n), b, c;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(all(a));
        
        for(int i = 0; i < a.size(); i++){
            if(a[i] != a.back()){
                b.push_back(a[i]);
            } else {
                c.push_back(a[i]);
            }
        }

        if(a.size() > 0 && b.size() > 0){

            cout << b.size() << " " << c.size() << "\n";
            
            for(int i = 0; i < b.size(); i++)
                cout << b[i] << " \n"[i+1==b.size()];

            for(int i = 0; i < c.size(); i++)
                cout << c[i] << " \n"[i+1==c.size()];
        } else {
            cout << -1 << "\n";
        }
    }
    
    return 0;   
}
