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
    
    int T;
    cin >> T;

    while(T--){
        string s, t;
        cin >> s >> t;

        vector<pair<char, int>> v(s.size());
        for(int i = 0; i < s.size(); i++)
            v[i] = make_pair(s[i], i);
        sort(all(v));

        bool ans = true;
        int pos = 0, cont = 1;
        vector<pair<char, int>>::iterator it;
        
        for(int i = 0; i < t.size() && ans; i++){
            it = lower_bound(all(v), make_pair(t[i], pos));
            if(it != v.end() && it->first == t[i]){
                pos = it->second + 1;
            }
            else{
                pos = 0;
                cont++;
                it = lower_bound(all(v), make_pair(t[i], pos));
                if(it != v.end() && it->first == t[i])
                    pos = it->second + 1;
                else
                    ans = false;
            }
        }

        cout << (ans ? cont : -1) << "\n";
    }
    
    return 0;   
}
