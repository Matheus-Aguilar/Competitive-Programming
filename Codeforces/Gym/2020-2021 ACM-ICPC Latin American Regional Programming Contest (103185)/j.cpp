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
#define MAXK 8

using namespace std;

int n, k, idx = 0, timer = 1;

unordered_map<int, int> cont;
unordered_map<int, int> last;

vector<int> q;

void update(vector<int> &v, int val){

    for(int i = 0; i < (1 << v.size()); i++){
        
        int hash = 0;

        for(int j = 0; j < v.size(); j++){
            if(i & (1 << j)){
                hash *= 10;
                hash += v[j];
            }
        }

        if(last[hash] != timer){
            cont[hash] += val;
            last[hash] = timer;
        }
    }

    timer++;
}

int main(){
    optimize;

    cin >> n >> k;

    vector<vector<int>> c(n);
    
    for(int i = 0; i < n; i++){
        char op;
        
        cin >> op;

        if(op == 'C'){
            
            int r;
            cin >> r;

            c[idx].resize(r);

            for(int j = 0; j < r; j++)
                cin >> c[idx][j];
            
            sort(all(c[idx]));
            
            idx++;
            update(c[idx - 1], 1);
        } 
        else if(op == 'D'){
            int pos;
            cin >> pos;
            update(c[pos - 1], -1);
        } 
        else {

            int r;
            cin >> r;

            q.resize(r);

            for(int j = 0; j < r; j++)
                cin >> q[j];
            
            sort(all(q));
            
            int hash = 0;
            
            for(int j = 0; j < r; j++){
                hash *= 10;
                hash += q[j];
            }

            cout << cont[hash] << "\n";
        }
    }

    return 0;   
}
