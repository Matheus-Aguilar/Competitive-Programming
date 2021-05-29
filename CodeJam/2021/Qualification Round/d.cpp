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

void get(int l, int r, int &i, int &j, int &k){
    
    i = rng() % (r - l + 1) + l;
    j = rng() % (r - l + 1) + l;
    k = rng() % (r - l + 1) + l;
    
    if(i == j)
        j = (j == r ? l : j + 1);
    if(i == k || j == k)
        k = (k == r ? l : k + 1);
    if(i == k || j == k)
        k = (k == r ? l : k + 1);
}

void solve(vector<int> &a, vector<int> &p, int l, int r, int type, int last){
    
    int x, y, z;
    int m, lm, rm;
    int q;

    if(r - l + 1 >= 3){

        get(l, r, x, y, z);

        q = query(a[x], a[y], a[z]);

        if(q == a[x]){
            m = x;
            lm = y;
            rm = z;
        }
        else if(q == a[y]){
            m = y;
            lm = x;
            rm = z;
        }
        else if(q == a[z]){
            m = z;
            lm = x;
            rm = y;
        }
    }
    
    if(type == MIDDLE){
        if(r - l + 1 <= 2)
            return;
    }
    else if(type == LEFT){
        if(r - l + 1 <= 1)
            return;
        else if(r - l + 1 == 2){
            q = query(a[l], a[r], a[last]);
            if(q == a[l]) 
                swap(a[l], a[r]);
            return;
        }
        else{
            q = query(a[m], a[rm], a[last]);

            if(q != a[rm])
                swap(lm, rm);
        }
    }
    else{
        if(r - l + 1 <= 1)
            return;
        else if(r - l + 1 == 2){
            q = query(a[l], a[r], a[last]);
            if(q == a[r]) 
                swap(a[l], a[r]);
            return;
        }
        else{
            q = query(a[m], a[lm], a[last]);

            if(q != a[lm])
                swap(lm, rm);
        }
    }

    p[m] = 0;
    p[lm] = -1;
    p[rm] = 1;

    for(int i = l; i <= r; i++){
        if(a[i] == a[x] || a[i] == a[y] || a[i] == a[z])
            continue;
        q = query(a[i], a[lm], a[m]);
        p[i] = (q == a[m] ? 1 : -1);
    }

    swap(a[r], a[m]);
    swap(p[r], p[m]);

    int i, j;

    for(i = l, j = l; i < r; i++){
        if(p[i] == -1){
            swap(a[i], a[j]);
            swap(p[i], p[j]);
            j++;
        }
    }

    swap(a[r], a[j]);
    swap(p[r], p[j]);

    solve(a, p, l, j - 1, LEFT, j);
    solve(a, p, j + 1, r, RIGHT, j);
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
