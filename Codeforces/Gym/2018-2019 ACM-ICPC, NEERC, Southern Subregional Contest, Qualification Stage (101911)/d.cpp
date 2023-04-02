#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MAXN 10001000

using namespace std;

unordered_set<int> ok;
unordered_map<int, vector<int>> fac;
unordered_map<int, vector<int>> upper;
unordered_map<int, vector<int>> last;

bool prime[MAXN];
int f[MAXN];

void sieve(){
    memset(prime, 1, sizeof(prime));

    for(ll i = 2; i < MAXN; i++){
        if(prime[i]){
            for(ll j = i * i; j < MAXN; j += i){
                f[j] = i;
                prime[j] = false;
            }
            f[i] = i;
        }
    }
}

void factor(int x){
    
    int y = x;
    vector<int> &lst = last[x], &up = upper[x], &fct = fac[x]; 

    while(y > 1){
        
        int p = f[y], cnt = 0;
        
        while(y % p == 0){
            y /= p;
            cnt++;
        }

        fct.push_back(p);
        up.push_back(cnt);
        lst.push_back(0);
    }
}

int build(vector<int> &lst, vector<int> &fct){
    int x = 1;

    for(int i = 0; i < lst.size(); i++){
        for(int j = 0; j < lst[i]; j++){
            x *= fct[i];
        }
    }

    return x;
}

int calc(int x){
    
    int pos = 0;
    vector<int> &lst = last[x], &up = upper[x], &fct = fac[x]; 

    while(pos < lst.size() && lst[pos] == up[pos]){
        pos++;
    }

    if(pos == lst.size())
        return -1;
    
    lst[pos]++;

    for(int i = 0; i < pos; i++)
        lst[i] = 0;
    
    return build(lst, fct);
}

int main() {
    optimize;

    sieve();

    int n;
    cin >> n;

    vector<pair<int, int>> ans(n);

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        if(ok.find(x) == ok.end()){
            factor(x);
            ok.insert(x);
            ans[i] = make_pair(1, x);
            continue;
        }

        int a = calc(x);

        if(a == -1){
            cout << "NO" << "\n";
            return 0;
        }

        ans[i] = make_pair(a, x / a);
    }

    cout << "YES" << "\n";

    for(int i = 0; i < n; i++)
        cout << ans[i].first << " " << ans[i].second << "\n";

    return 0;
}