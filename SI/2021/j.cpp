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

ll getProd(string &s){
    ll prod = 1LL;

    for(int i = 0; i < s.size(); i++){
        prod *= (s[i] - '0');
    }

    return prod;
}

int main(){
    optimize;

    string s;
    cin >> s;

    vector<int> cont(10, 0);

    for(int i = 0; i < s.size(); i++){
        int c = s[i] - '0';
        cont[c]++;
    }

    bool ok = true;

    for(int i = 0; i < 10; i++){
        if(cont[i] > 1){
            ok = false;
        }
    }

    if(!ok){
        cout << "NAO" << "\n";
        return 0;
    }

    set<ll> prods;

    for(int i = 0; i < s.size() && ok; i++){
        for(int j = i; j < s.size() && ok; j++){
            
            string sub = s.substr(i, (j - i + 1));
            ll prod = getProd(sub);

            if(prods.find(prod) != prods.end()){
                ok = false;
            }

            prods.insert(prod);
        }
    }
    
    cout << (ok ? "SIM" : "NAO") << "\n";

    return 0;   
}
