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

int n, m, sc = 0;
vector<int> c;
string sol;
bitset<30> bc;

bool check(int k, bitset<30> &b, vector<bitset<30>> &ans){

    for(int i = 0; i < n; i++){

        bc = (b ^ ans[i]);
        bc.flip();
        int cont = bc.count();

        cout << "I: " << ans[i] << "\n";
        cout << "Cont: " << cont << "\n";

        if(cont > c[i] || cont + (m - k) < c[i])
            return false;
    }

    return true;
}

void bt(int k, bitset<30> &b, vector<bitset<30>> &ans){
    
    cout << "Check: " << b.to_string() << "\n";

    if(!check(k, b, ans))
        return;
    
    if(k == m){
        
        if(sc == 0)
            sol = b.to_string();
        sc++;

        return;
    }

    b.set(k, false);
    bt(k + 1, b, ans);
    
    b.set(k, true);
    bt(k + 1, b, ans);
}

int main(){
    optimize;

    int T;
    cin >> T;

    while(T--){
        cin >> n >> m;

        c.resize(n);
        
        string aux;
        vector<bitset<30>> ans(n);
        bitset<30> b;

        for(int i = 0; i < n; i++){
            
            cin >> aux >> c[i];

            ans[i].reset();
        
            for(int j = 0; j < aux.size(); j++){
                if(aux[j] == '1')
                    ans[i].set(j, true);
            }
        }

        sc = 0;
        sol = "";
        b.set();

        bt(0, b, ans);

        if(sc == 1)
            cout << sol << "\n";
        else
            cout << sc << " solutions" << "\n";
        
        c.clear();
    }
    
    return 0;   
}
