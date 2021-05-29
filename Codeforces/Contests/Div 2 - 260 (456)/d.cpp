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
#define MAXN 100000

using namespace std;

struct TrieNode{
    int c[26];
    bool leaf = true;
    TrieNode(){ memset(c, -1, sizeof(c)); }
    const int & operator[](size_t i) const{ return c[i]; }
    int & operator[](size_t i){ return c[i]; }
};

struct Trie{
    int size = 0;
    vector<TrieNode> t;
    
    Trie(int n){ 
        t.resize(n + 1); 
    }
    void add(const string &s){
        int pos = 0;
        for(int i = 0; i < s.size(); i++){
            int c = (int)(s[i] - 'a');
            if(t[pos][c] == -1)
                t[pos][c] = ++size;
            t[pos].leaf = false;
            pos = t[pos][c];
        }
    }
    pair<bool, bool> query(int pos = 0) const{
        if(t[pos].leaf)
            return make_pair(false, true);
        else{
            pair<bool, bool> ans = make_pair(false, false);
            for(int i = 0; i < 26; i++){
                if(t[pos][i] != -1){
                    pair<bool, bool> child = query(t[pos][i]);
                    ans.first |= !child.first;
                    ans.second |= !child.second;
                }
            }
            return ans;
        }
    }
};

int main(){
    optimize;
    
    int n, k;
    cin >> n >> k;

    Trie t(MAXN);
    while(n--){
        string s;
        cin >> s;
        t.add(s);
    }

    pair<bool, bool> ans = t.query();

    if(!ans.first)
        cout << "Second" << "\n";
    else if(ans.second)
        cout << "First" << "\n";
    else
        cout << (k % 2 ? "First" : "Second") << "\n";

    return 0;   
}
