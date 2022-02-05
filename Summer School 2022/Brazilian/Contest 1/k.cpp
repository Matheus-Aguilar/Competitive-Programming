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

int q;

// Trie de Bits
// Complexidade N log(MAX Ai)

//Alguns exercícios podem considerar que o número 0 já esteja na trie
//p = posição do nodo
//q = contador
//f = final

const int t = 26;
int z;
const char desc = '0';

struct Node{
    vector<int> p,q;
    int f;

    Node(){
        p.assign(t, -1);
        q.assign(t, 0);
        f = 0;
    }
};

vector<Node> trie(1);

string base2(ll x){
    string aux;

    for(int i=60;i>=0;i--) {
        if( (x & (1LL << i)) )  aux.pb('1');
        else                     aux.pb('0');    
    }

    return aux;
}

void add(string &str){

    int u = 0;

    for(int i=0;i<str.size();i++){
        int c = str[i] - desc;

        if(trie[u].p[c] == -1){
            trie[u].p[c] = ++z;
            trie.emplace_back();
        }

        trie[u].q[c]++;
        u = trie[u].p[c];
    }

    trie[u].f++;
}

void remove(string &str){

    int u = 0;

    for(int i=0;i<str.size();i++){
        int c = str[i] - desc;

        trie[u].q[c]--;
        u = trie[u].p[c];
    }

    trie[u].f--;
}

ll query(string &str){

    string str = base2(x);

    ll ans = 0;
    int u = 0;

    for(int i=0;i<str.size();i++){
        int c = str[i] - desc;

        //Montar sua querie aqui
    }

    return ans;
}

int main(){
    optimize;
    
    cin >> q;

    return 0;   
}
