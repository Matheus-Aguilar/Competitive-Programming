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

int main(){
    optimize;
    
    int n, k;
    cin >> n >> k;

    multiset<int> m;
    vector<int> c(k);
    vector<vector<int>> t(1);

    for(int i = 0; i < n; i++){
        int mi;
        cin >> mi;
        m.insert(mi);
    }

    for(int i = 0; i < k; i++)
        cin >> c[i];
    reverse(all(c));

    int cont = 0;

    while(!m.empty()){
        int pos = c.end() - lower_bound(all(c), cont + 1);
        //cerr << pos << " " << m.size() << "\n";
        if(pos == 0){
            cont = 0;
            t.emplace_back();
            continue;
        }
        multiset<int>::iterator it = m.upper_bound(pos);
        if(it == m.begin()){
            cont = 0;
            t.emplace_back();
            continue;
        }
        else{
            it--;
            cont++;
            t.back().push_back(*it);
            m.erase(it);    
        }
    }

    cout << t.size() << "\n";
    for(int i = 0; i < t.size(); i++){
        cout << t[i].size() << " ";
        for(int j = 0; j < t[i].size(); j++){
            cout << t[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;   
}
