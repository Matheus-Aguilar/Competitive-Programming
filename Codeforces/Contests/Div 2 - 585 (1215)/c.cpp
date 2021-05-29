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

    string s, t;
    cin >> s >> t;

    bool possible = true;
    vector<pii> ans;
    vector<int> ab, ba;

    for(int i = 0; i < n; i++){
        if(s[i] != t[i]){
            if(s[i] == 'a')
                ab.push_back(i);
            else
                ba.push_back(i);
        }
    }

    while(ab.size() >= 2){
        int x = ab.back();
        ab.pop_back();
        int y = ab.back();
        ab.pop_back();
        ans.push_back(make_pair(x, y));
    }

    while(ba.size() >= 2){
        int x = ba.back();
        ba.pop_back();
        int y = ba.back();
        ba.pop_back();
        ans.push_back(make_pair(x, y));
    }

    if(ab.size() > 0 && ba.size() > 0){
        ans.push_back(make_pair(ab.back(), ab.back()));
        ans.push_back(make_pair(ab.back(), ba.back()));
    }
    else if(ab.size() > 0 || ba.size() > 0)
        possible = false;

    if(!possible)
        cout << -1 << "\n";
    else{
        cout << ans.size() << "\n";
        for(int i = 0; i < ans.size(); i++)
            cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }
    
    return 0;   
}
