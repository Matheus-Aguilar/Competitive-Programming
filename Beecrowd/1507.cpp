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
        string s;
        cin >> s;
        vector<pair<char, int>> v(s.size());
        for(int i = 0; i < s.size(); i++)
            v[i] = make_pair(s[i], i);
        sort(all(v));

        int q;
        cin >> q;
        while(q--){
            string r;
            cin >> r;
            

            bool ans = true;
            int pos;
            vector<pair<char, int>>::iterator it = lower_bound(all(v), make_pair(r[0], 0));
            
            if(it == v.end() || it->first != r[0]){
                cout << "No" << "\n";
                ans = false;
            }
            else
                pos = it->second;

            for(int i = 1; i < r.size() && ans; i++){
                it = lower_bound(all(v), make_pair(r[i], pos + 1));
                if(it == v.end() || it->first != r[i])
                    ans = false;
                else
                    pos = it->second;
            }

            cout << (ans ? "Yes" : "No") << "\n";
        }
    }
    
    return 0;   
}
