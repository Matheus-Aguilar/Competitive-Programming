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
        string a, b;
        int ans = 0, cont[26] = {0};
        
        cin >> a >> b;
        
        for(int i = 0; i < b.size(); i++)
            cont[b[i] - 'a']++;
        
        for(int i = 0; i < a.size(); i++){
            if(cont[a[i] - 'a'] > 0){
                cont[a[i] - 'a']--;
                ans++;
            }
            else{
                break;
            }
        }

        cout << ans << "\n";
    }
    
    return 0;   
}
