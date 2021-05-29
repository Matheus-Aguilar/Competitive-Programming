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
        vector<int> a(n);
        int even = -1;
        pii odd = pii(-1, -1);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] & 1){
                if(odd.first == -1) odd.first = i + 1;
                else odd.second = i + 1;
            }
            else{
                even = i + 1;
            }
        }
        if(odd.second != -1){
            cout << 2 << "\n" << odd.first << " " << odd.second << "\n";
        }
        else if(even != -1){
            cout << 1 << "\n" << even << "\n";
        }
        else{
            cout << -1 << "\n";
        }
    }

    return 0;   
}
