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

int n, m, cont = 0;
ll p[16], b[16], v[(1 << 16)];

map<int, vector<int>> mask;

int main(){
    optimize;
    
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> b[i];
    
    for(int i = 0; i < m; i++)
        cin >> p[i];

    for(int i = 0; i < (1 << m); i++){
        
        int sum = 0;
        
        for(int j = 0; j < m; j++){
            if(i & (1 << j)){
                sum += p[j];
            }
        }

        mask[sum].push_back(i);
    }

    for(auto it : mask){
        
        int sum = it.first;
        vector<int> &m = it.second;

        bool ok = false;

        for(int i = 0; i < m.size() && !ok; i++){
            for(int j = i; j < m.size() && !ok; j++){
                if((m[i] & m[j]) == 0){
                    ok = true;
                    v[cont++] = 2 * sum;
                }
            }   
        }
    }

    set<int> s;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < cont; j++){
            s.insert(b[i] + v[j]);
        }
    }

    for(auto it : s){
        cout << it << "\n";
    }

    return 0;   
}
