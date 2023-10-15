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

    string s, t;
    cin >> s >> t;

    vector<vector<int>> pos(26);

    for(int i = 0; i < s.size(); i++)
        pos[s[i] - 'a'].push_back(i);
    
    int last = -1, i = 0, cnt = 1;

    while(i < t.size()){
        int p = t[i] - 'a';
        int idx = upper_bound(all(pos[p]), last) - pos[p].begin();

        if(idx == pos[p].size()){
            last = -1;
            cnt++;
        } else {
            last = pos[p][idx];
            i++;
        }
    }

    cout << cnt << "\n";
    
    return 0;   
}
