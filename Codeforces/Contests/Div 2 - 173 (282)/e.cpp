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
#define MAXN 100100

using namespace std;

struct Node{
    int l, r;
    Node(int _l = -1, int _r = -1) : l(_l), r(_r){}
};

ll a[MAXN];
vector<Node> trie(1);

void add(ll x){
    int i = 0, j = 40;
    while(j--){
        if(x & (1LL << j)){
            if(trie[i].r != -1)
                i = trie[i].r;
            else{
                i = trie[i].r = trie.size();
                trie.emplace_back();
            }
        }
        else{
            if(trie[i].l != -1)
                i = trie[i].l;
            else{
                i = trie[i].l = trie.size();
                trie.emplace_back();
            }
        }
    }
}

ll query(ll x){
    int i = 0, j = 40;
    ll k = 0;
    while(j--){
        if(x & (1LL << j)){
            if(trie[i].l == -1){
                k |= (1LL << j);
                i = trie[i].r;
            }
            else{
                i = trie[i].l;
            }
        }
        else{
            if(trie[i].r == -1){
                i = trie[i].l;
            }
            else{
                k |= (1LL << j);
                i = trie[i].r;
            }
        }
    }
    return k;
}

int main(){
    optimize;
    
    int n;
    ll prefix = 0, suffix = 0, best = 0;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        prefix ^= a[i];
    }

    add(0LL);
    best = max((prefix ^ query(prefix)), best);

    for(int i = n - 1; i >= 0; i--){
        prefix ^= a[i];
        suffix ^= a[i];
        add(suffix);
        best = max((prefix ^ query(prefix)), best);
    }

    cout << best << "\n";

    return 0;   
}
