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

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        
        string s;
        cin >> s;

        for(int j = 0; j < s.size(); j++){
            bool duplicate = true;
            
            if(j > 0 && s[j - 1] == s[j])
                duplicate = false;
            if(j + 1 < s.size() && s[j + 1] == s[j])
                duplicate = false;
            
            cout << s[j];
            
            if(duplicate)
                cout << s[j];
        }

        cout << "\n";
    }
    
    return 0;   
}
