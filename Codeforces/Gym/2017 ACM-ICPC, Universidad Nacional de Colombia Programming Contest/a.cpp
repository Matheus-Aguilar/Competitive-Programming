#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll unsigned long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))
#define MAXN 1000010

using namespace std;

struct Node{
    Node *c[10] = {NULL};
};

int k = 0;
Node *root = new Node;

void insert(string &s){
    Node *pos = root;
    int i = 0;
    while(i < s.size()){
        int c = (s[i] - '0');
        if(pos->c[c] == NULL)
            pos->c[c] = new Node;        
        pos = pos->c[c];
        i++;
    }
}

ll queryMax(string &s){
    
    Node *pos = root;
    int j = 0;

    string best = "";
    string ans = "";
    
    while(j < s.size()){

        bool nxt = false;

        int c = (s[j] - '0'), v = 9;

        for(int i = 9 - c; i >= 0 && !nxt; i--, v--){
            if(pos->c[i] != NULL){
                ans += (v + '0');
                best += (i + '0');
                pos = pos->c[i];
                nxt = true;
            }
        }

        if(nxt){
            j++;
            continue;
        }

        for(int i = 9; i >= 10 - c && !nxt; i--, v--){
            if(pos->c[i] != NULL){
                ans += (v + '0');
                best += (i + '0');
                pos = pos->c[i];
                nxt = true;
            }
        }       

        j++;

        if(!nxt) return 0LL;
    }

    return stoll(ans);
}

ll queryMin(string &s){
    
    Node *pos = root;
    int j = 0;

    string best = "";
    string ans = "";
    
    while(j < s.size()){

        bool nxt = false;

        int c = (s[j] - '0'), v = 0;

        for(int i = 10 - c; i <= 9 && !nxt; i++, v++){
            if(pos->c[i] != NULL){
                ans += (v + '0');
                pos = pos->c[i];
                nxt = true;
            }
        }

        if(nxt){
            j++;
            continue;
        }

        for(int i = 0; i <= 9 - c && !nxt; i++, v++){
            if(pos->c[i] != NULL){
                ans += (v + '0');
                pos = pos->c[i];
                nxt = true;
            }
        }

        j++;

        if(!nxt) return INFLL;
    }

    return stoll(ans);
}

int main(){
    optimize;

    int n;
    ll high = 0, low = INFLL;
    string s;

    cin >> n;

    for(int i = 0; i < n; i++){
        
        cin >> s;
        
        while(s.size() < 19)
            s = "0" + s;
        
        high = max(high, queryMax(s));
        low = min(low, queryMin(s));
        
        insert(s);
    }

    cout << low << " " << high << "\n";
    
    return 0;   
}
