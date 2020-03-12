#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;
    
    string s;
    cin >> s;

    vector<ll> sizeOne(26, 0);
    vector<ll> sizeTwo(26 * 26, 0);
    vector<vector<ll>> dp(s.size(), vector<ll>(26, 0));

    for(int i = 0; i < s.size(); i++){
        int pos = (int)(s[i] - 'a');
        sizeOne[pos]++;
        for(int j = 0; j < 26; j++){
            if(i) dp[i][j] = dp[i - 1][j] + (int)(j == pos);
            else dp[i][j] = (int)(j == pos);
        }
    }

    for(int i = 0;  i < 26; i++){
        for(int j = 0; j < 26; j++){
            int found = 0;
            for(int k = 1; k < s.size() && found < sizeOne[j]; k++){
                int pos = (int)(s[k] - 'a');
                if(pos == j){ 
                    sizeTwo[i * 26 + j] += dp[k - 1][i];
                    found++;
                }
            }
        }
    }

    cout << max(*max_element(sizeOne.begin(), sizeOne.end()), *max_element(sizeTwo.begin(), sizeTwo.end())) << "\n";

    return 0;   
}
