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

    int k;
    vector<vector<int>> pos(26);

    string s, ans = "";

    cin >> s >> k;

    for(int i = s.size() - 1; i >= 0; i--)
        pos[s[i] - 'a'].push_back(i);

    while(k > 0){
        for(int i = 0; i < 26; i++){
            if(!pos[i].empty() && pos[i].back() <= s.size() - k){
                
                ans += (i + 'a');

                for(int j = i + 1; j < 26; j++){
                    while(!pos[j].empty() && pos[j].back() < pos[i].back()){
                        pos[j].pop_back();
                    }
                }

                pos[i].pop_back();
                k--;

                break;
            }
        }
    }

    cout << ans << "\n";
    
    return 0;   
}
