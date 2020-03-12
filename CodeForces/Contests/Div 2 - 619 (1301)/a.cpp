#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;

    int n;
    cin >> n;
    while(n--){
        string a, b, c;
        cin >> a >> b >> c;
    
        bool ok = true;

        for(int i = 0; i < a.size(); i++){
            if(b[i] != c[i] && a[i] != c[i]){
                ok = false;
                break;
            }
        }
    
        cout << (ok ? "YES" : "NO") << "\n";
    
    }
    return 0;   
}
