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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int LEFT = -1, RIGHT = 1, MIDDLE = 0;

bool answer(vector<int> &a, int n){
    
    int q;
    
    for(int i = 0; i < n - 1; i++)
        cout << a[i] << " ";
    cout << a[n - 1] << endl;

    cin >> q;

    return q == 1;
}

int query(int i, int j, int k){
    
    int q;
    
    cout << i << " " << j << " " << k << endl;
    cin >> q;

    if(q == -1){
        assert(false);
        exit(0);
    }

    return q;
}

void get(int l, int r, int &i, int &j){
    const int sz = (r - l + 1);

    i = rng() % sz;
    j = rng() % sz;

    while(i == j)
        j = (j + 1) % sz;
    
    i += l;
    j += l;
}

void get(int l, int r, int &i, int &j, int &k){
    
    const int sz = (r - l + 1);

    i = rng() % sz;
    j = rng() % sz;
    k = rng() % sz;

    while(i == j)
        j = (j + 1) % sz;
    while(i == k || j == k)
        k = (k + 1) % sz;
    
    i += l;
    j += l;
    k += l;
}

void solve(vector<int> &a, vector<int> &p, int l, int r, int type, int last){
    
    int m, lm, rm;
    int c0 = 1, c1 = 1, c2 = 0;
    int q;

    if(type == MIDDLE){

        if(r - l + 1 <= 2)
            return;
        
        get(l, r, m, lm, rm);

        q = query(a[m], a[lm], a[rm]);
        
        if(q == a[lm]){
            lm = m;
        }
        else if(q == a[rm]){
            rm = m;
        }
    }
    else{

        if(r - l + 1 <= 1)
            return;
        
        get(l, r, lm, rm);    

        if(type == LEFT){
            q = query(a[lm], a[rm], a[last]);
            if(q == a[lm])
                swap(lm, rm);
        }
        else{
            q = query(a[lm], a[rm], a[last]);
            if(q == a[rm])
                swap(lm, rm);
        }
    }

    p[lm] = 0;
    p[rm] = 1;

    for(int i = l; i <= r; i++){
        
        if(i == lm || i == rm)
            continue;
        
        q = query(a[lm], a[rm], a[i]);
        
        if(q == a[lm]){
            p[i] = 0;
            c0++;
        }
        else if(q == a[i]){
            p[i] = 1;
            c1++;
        }
        else{
            p[i] = 2;
            c2++;
        }
    }

    if(rm == r - 1)
        rm = lm;

    swap(a[lm], a[r - 1]);
    swap(p[lm], p[r - 1]);    

    swap(a[rm], a[r]);
    swap(p[rm], p[r]);

    for(int i = l, j = l; i < r; i++){
        if(p[i] == 0){
            swap(a[i], a[j]);
            swap(p[i], p[j]);
            j++;
        }
    }

    for(int i = l + c0, j = l + c0; i <= r; i++){
        if(p[i] == 1){
            swap(a[i], a[j]);
            swap(p[i], p[j]);
            j++;
        }
    }

    solve(a, p, l, l + c0 - 2, LEFT, l + c0 - 1);
    solve(a, p, l + c0, l + c0 + c1 - 2, LEFT, l + c0 + c1 - 1);
    solve(a, p, l + c0 + c1, r, RIGHT, l + c0 + c1 - 1);
}

int main(){
    //optimize;

    int t, n, q;
    cin >> t >> n >> q;

    vector<int> a(n);
    vector<int> p(n);

    while(t--){

        iota(all(a), 1);

        solve(a, p, 0, n - 1, MIDDLE, -1);
        
        if(!answer(a, n)){
            assert(false);
            return 0;
        }
    }
    
    return 0;   
}
