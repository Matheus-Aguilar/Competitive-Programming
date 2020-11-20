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

int main() {
    
    optimize;
    
    string s1, s2;
    
    cin >> s1 >> s2;
    
    vector<vector<int>> pos(26);
    
    for(int i = 0; i < (int)s2.size(); i++){
        pos[(int)(s2[i] - 'a')].push_back(i);
    }
    
    bool ans = true;
    int idx = 0;
    
    for(int i = 0; i < (int)s1.size() && ans; i++){
        int c = (int)(s1[i] - 'a');
        auto it = lower_bound(pos[c].begin(), pos[c].end(), idx); 
        if(it == pos[c].end())
            ans = false;
        else
            idx = *it + 1;
    }
    
    cout << (ans ? "SIM" : "NAO") << "\n";
    
    return 0;
}
