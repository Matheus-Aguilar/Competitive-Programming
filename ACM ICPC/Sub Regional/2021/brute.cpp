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

map<int, string> best;

vector<string> gen(int n){

    vector<string> v;

    for(int i = 0; i < (1 << n); i++){
        string s = "";

        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                s += 'A';
            }
            else{
                s += 'B';
            }
        }

        if(s.back() == 'A') continue;

        v.push_back(s);
    }

    return v;
}

int calc(string &s, int n){
    
    vector<int> dp(n + 1);

    dp[n] = 1;
    dp[n - 1] = 1;

    for(int i = n - 2; i >= 0; i--){
        if(s[i] == 'A')
            dp[i] = dp[i + 1] + dp[i + 2];
        else
            dp[i] = dp[i + 1];
    }

    return dp[0];
}

int main(){
    optimize;

    for(int i = 1; i < 10; i++){

        vector<string> s = gen(i);

        for(int j = 0; j < s.size(); j++){
            int cont = calc(s[j], s[j].size());

            if(best.find(cont) == best.end()){
                best[cont] = s[j];
            }
            else{
                best[cont] = min(best[cont], s[j]);
            }
        }
    }

    for(auto i : best){
        cout << i.first << ": " << i.second << "\n";
    }

    return 0;   
}
