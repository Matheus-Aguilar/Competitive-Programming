#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int mapa(char c){
    return (int)(c - 'a');
}

int ans[26];

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        memset(ans, 0, sizeof(ans));        
        string s;
        vector<int> p(m); 

        cin >> s;
        for(int i = 0; i < m; i++) cin >> p[i];

        sort(p.begin(), p.end());
        p.push_back(n + 1);

        for(int i = 0; i < s.size(); i++){
            int pos = lower_bound(p.begin(), p.end(), i + 1) - p.begin();
            pos = m + 1 - pos;
            //cout << s[i] << " " << pos << "\n";
            ans[mapa(s[i])] += pos;
        }

        for(int i = 0; i < 26; i++) cout << ans[i] << " ";
        cout << "\n";
    }
    
    return 0;   
}
