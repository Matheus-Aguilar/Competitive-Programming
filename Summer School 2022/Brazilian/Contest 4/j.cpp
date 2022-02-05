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

typedef tuple<string, int, int> Word;

int n;

vector<int> nxt;
vector<Word> words;

void generateStr(string &str, int idx){
    for(int i = 1; i < (1 << str.size()); i++){
        string s = "";

        for(int j = 0; j < str.size(); j++){
            if(i & (1 << j)){
                s += str[j];
            }
        }

        words.emplace_back(s, idx, s.size());
    }
}

int dp[(1 << 20)][20];

int solve(int i, int j){

    if(j == n) return 0;
    if(i == words.size()) return -INF;
    
    if(dp[i][j] == -1){
        dp[i][j] = solve(i + 1, j);

        if(get<1>(words[i]) == j){
            dp[i][j] = max(dp[i][j], solve(nxt[i], j + 1) + get<2>(words[i]));
        }
    }

    return dp[i][j];
}

int main(){
    optimize;

    ms(dp, -1);
    
    cin >> n;

    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        generateStr(str, i);
    }

    sort(all(words));


    nxt.resize(words.size());


    for(int i = 0; i < words.size(); i++){
        string str = get<0>(words[i]);
        nxt[i] = upper_bound(all(words), Word(str, INF, INF)) - words.begin();
    }


    int ans = solve(0, 0);

    cout << (ans > 0 ? ans : -1) << "\n";

    return 0;   
}
