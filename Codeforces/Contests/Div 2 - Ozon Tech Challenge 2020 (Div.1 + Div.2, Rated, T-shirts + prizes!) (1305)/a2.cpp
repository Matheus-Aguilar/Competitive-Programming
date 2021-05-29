#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;
    
    int t;
    cin >> t;

    while(t--){
        int n, m, sum = 0;
        cin >> n >> m;
        while(n--){
            int x;
            cin >> x;
            sum += x;
        }

        cout << min(sum, m) << "\n";
    }

    return 0;   
}
