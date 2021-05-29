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

struct cmp{
    bool operator()(const string &a, const string &b) const{
        for(int i = 0; i < min(a.size(), b.size()); i++){
            if(a[i] < b[i])
                return true;
            else if(b[i] < a[i])
                return false;
        }
        return a.size() < b.size();
    }
};

int main(){
    optimize;
    
    int t;
    cin >> t;
    while(t--){
        int n, k, i;
        cin >> n >> k;
    
        string s, aux;
        cin >> s;
        sort(all(s));
        if(s[0] != s[k - 1])
            cout << s[k - 1] << "\n";
        else{
            bool allEqual = true;
            for(int i = k + 1; i < n && allEqual; i++)
                allEqual = s[i - 1] == s[i];
            if(allEqual){
                cout << s[0] << s.substr(k, (n - 1)/k) << "\n";
            }
            else{
                cout << s[0] << s.substr(k, n - k) << "\n";
            }
        }
    }

    return 0;   
}
