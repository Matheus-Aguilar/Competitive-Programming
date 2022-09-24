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

//SegTree sem lazy de propagation
//Complexidade: O(n * log n) + O(m * log N) sendo n a quantidade de operações e m a quantidade de elementos 
//Talvez seja necessário fazer um combine para unir os segmentos

#define MAXN 100100

int n;
ll sum[MAXN];

void upd(int l, int r, int x){
    sum[l] += x;
    sum[r + 1] -= x;
}

int main(){
    optimize;

    cin >> n;

    vector<ll> h(n);
    vector<pair<ll, int>> ord(n);
    set<int> pos;

    for(int i = 0; i < n; i++){
        cin >> h[i];
        ord[i] = make_pair(h[i], i);
    }

    sort(all(ord));
    reverse(all(ord));
    
    for(int i = 0; i < n; i++){
        
        int p = ord[i].second;

        pos.insert(p);

        if(p != *pos.begin()){
            auto it = pos.find(p);
            it--;
            int sz = (p - *it - 1) / 2;
            if(sz > 0) upd(p - sz, p - 1, 1);
        }
        else{
            if(p != 0){
                upd(0, p - 1, 1);
            }
        }

        if(p != *pos.rbegin()){
            auto it = pos.find(p);
            it++;
            int sz = (*it - p - 1) / 2;
            if(sz > 0) upd(p + 1, p + sz, 1);
        }
        else{
            if(p != n - 1){
                upd(p + 1, n - 1, 1);
            }
        }
    }

    for(int i = 1; i < n; i++){
        sum[i] += sum[i - 1];
    }

    for(int i = 0; i < n; i++)
        cout << sum[i] << " \n"[i==n-1];

    return 0;   
}
