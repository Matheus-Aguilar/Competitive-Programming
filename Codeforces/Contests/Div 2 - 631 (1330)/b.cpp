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
        vector<int> prefix(n, false);
        vector<int> suffix(n, false);
        
        set<int> s;
        
        for(int i = 0; i < n; i++) cin >> a[i];
        
        for(int i = 0; i < n; i++){
            if(s.insert(a[i]).second){
                if(s.size() == (*s.rbegin()))
                    prefix[i] = true;
            }
            else{
                break;
            }
        }

        s.clear();

        for(int i = n - 1; i >= 0; i--){
            if(s.insert(a[i]).second){
                if(s.size() == (*s.rbegin()))
                    suffix[i] = true;
            }
            else{
                break;
            }
        }

        int cont = 0;
        vector<pii> ans;
        for(int i = 0; i < n - 1; i++){
            if(prefix[i] && suffix[i + 1]){
                cont++;
                ans.push_back(pii(i + 1, n - i - 1));
            }
        }

        cout << cont << "\n";
        for(auto i:ans) cout << i.first << " " << i.second << "\n";
    }
    
    return 0;   
}
