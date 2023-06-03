#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MAXN 100100

using namespace std;

ll seg[4 * MAXN], lazy1[4 * MAXN], lazy2[4 * MAXN];

void build(int t, int tl, int tr){
    if(tl == tr){
        seg[t] = -1;
    } else {
        int tm = tl + (tr - tl) / 2;
        build(2 * t, tl, tm);
        build(2 * t + 1, tm + 1, tr);
        seg[t] = seg[2 * t] + seg[2 * t + 1];
    }
    lazy1[t] = -1;
}

void build2(int t, int tl, int tr){
    if(tl == tr){
        seg[t] = 0;
    } else {
        int tm = tl + (tr - tl) / 2;
        build2(2 * t, tl, tm);
        build2(2 * t + 1, tm + 1, tr);
        seg[t] = seg[2 * t] + seg[2 * t + 1];
    }
    lazy2[t] = 0;
}

void push1(int t, int tl, int tr){
    if(lazy1[t] != -1){
        seg[t] = (tr - tl + 1) * lazy1[t];
        if(tl != tr){
            lazy1[2 * t] = lazy1[t];
            lazy1[2 * t + 1] = lazy1[t];
        }
    }
    lazy1[t] = -1;
}

void push2(int t, int tl, int tr){
    if(lazy2[t] != 0){
        seg[t] += (tr - tl + 1) * lazy2[t];
        if(tl != tr){
            lazy2[2 * t] += lazy2[t];
            lazy2[2 * t + 1] += lazy2[t];
        }
    }
    lazy2[t] = 0;
}

void push(int t, int tl, int tr, int mode){
    if(mode == 1)
        push1(t, tl, tr);
    else
        push2(t, tl, tr);
}

void update(int t, int tl, int tr, int l, int r, int x, int mode){
    
    push(t, tl, tr, mode);

    if(tl > r || tr < l)
        return;
    if(l <= tl && tr <= r){
        if(mode == 1)
            lazy1[t] = x;
        else
            lazy2[t] = x;
        push(t, tl, tr, mode);
    } else {
        int tm = tl + (tr - tl) / 2;
        update(2 * t, tl, tm, l, r, x, mode);
        update(2 * t + 1, tm + 1, tr, l, r, x, mode);
        seg[t] = seg[2 * t] + seg[2 * t + 1];
    }
}

ll query(int t, int tl, int tr, int l, int r, int mode){
    
    push(t, tl, tr, mode);
    
    if(tl > r || tr < l)
        return 0LL;
    if(l <= tl && tr <= r){
        return seg[t];
    } else {
        int tm = tl + (tr - tl) / 2;
        ll q1 = query(2 * t, tl, tm, l, r, mode);
        ll q2 = query(2 * t + 1, tm + 1, tr, l, r, mode);
        return q1 + q2;
    }
}

struct Joke{
    int x, i, k;
    bool operator<(const Joke &j){
        if(i != j.i)
            return i < j.i;
        if(x != j.x)
            return x < j.x;
        return k < j.k;
    }
};

int n, m;

int main(){

    optimize;

    int t;
    cin >> t;

    while(t--){
        cin >> n >> m;

        vector<Joke> jokes(m);
        unordered_map<int, vector<int>> check(m);

        build(1, 0, n - 1);

        for(int i = 0; i < m; i++){
            cin >> jokes[i].x >> jokes[i].i >> jokes[i].k;
            jokes[i].x--;
        }

        for(int i = 0; i < m; i++){
            update(1, 0, n - 1, max(0, jokes[i].x - jokes[i].k), min(n - 1, jokes[i].x + jokes[i].k), jokes[i].i, 1);
        }

        for(int i = 0; i < n; i++){
            ll last = query(1, 0, n - 1, i, i, 1);
            if(last != -1)
                check[last].push_back(i);
        }
        
        sort(jokes.begin(), jokes.end());

        build2(1, 0, n - 1);
        
        int pos = 0, ans = n;

        while(pos < jokes.size()){
            
            int type = jokes[pos].i;
            int aux = pos;

            while(pos < jokes.size() && jokes[pos].i == type){
                update(1, 0, n - 1, max(0, jokes[pos].x - jokes[pos].k), min(n - 1, jokes[pos].x + jokes[pos].k), 1, 2);
                pos++;
            }
            
            for(int j = 0; j < check[type].size(); j++){
                int k = check[type][j];
                ll q = query(1, 0, n - 1, k, k, 2);
                if(q == 1){
                    ans--;
                }
            }

            while(aux < jokes.size() && jokes[aux].i == type){
                update(1, 0, n - 1, max(0, jokes[aux].x - jokes[aux].k), min(n - 1, jokes[aux].x + jokes[aux].k), -1, 2);
                aux++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}