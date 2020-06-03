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
#define MAXN 200100

using namespace std;

struct TrieNode{
    int l, r, c;
    TrieNode(int _l = -1, int _r = -1, int _c = 0): l(_l), r(_r), c(_c){}
};

struct Trie{
    int size = 0;
    vector<TrieNode> t;
    
    Trie(int n){
        t.resize(64 * n + 1);
    }
    void add(int x){
        int pos = 0;
        for(int i = 30; i >= 0; i--){
            if(x & (1 << i)){
                if(t[pos].r == -1)
                    t[pos].r = ++size;
                pos = t[pos].r;
            }
            else{
                if(t[pos].l == -1) 
                    t[pos].l = ++size;
                pos = t[pos].l;
            }
            t[pos].c++;
        }
    }
    void remove(int x){
        int pos = 0;
        for(int i = 30; i >= 0; i--){
            if(x & (1 << i))
                pos = t[pos].r;
            else
                pos = t[pos].l;
            t[pos].c--;
        }
    }
    int query(int x){
        int pos = 0, ans = 0;
        for(int i = 30; i >= 0; i--){
            if(x & (1 << i)){
                if(t[pos].l != -1 && t[t[pos].l].c){
                    ans |= (1 << i);
                    pos = t[pos].l;
                }
                else{
                    pos = t[pos].r;
                }
            }
            else{
                if(t[pos].r != -1 && t[t[pos].r].c){
                    ans |= (1 << i);
                    pos = t[pos].r;
                }
                else{
                    pos = t[pos].l;
                }
            }
        }
        return ans;
    }
};

int main(){
    optimize;

    int n, x;
    char c;

    cin >> n;

    Trie t(n);
    t.add(0);

    while(n--){
        cin >> c >> x;
        if(c == '+')
            t.add(x);
        else if(c == '-')
            t.remove(x);
        else
            cout << t.query(x) << "\n";
    }
    
    return 0;   
}
