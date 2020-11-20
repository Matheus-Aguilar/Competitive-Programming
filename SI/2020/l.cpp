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

using namespace std;

int main(){
    optimize;
    
    int l;
    cin >> l;

    vector<int> v(l);

    for(int i = 0; i < l; i++)
        cin >> v[i];

    set<int> now, solution;

    for(int i = 0; i < l; i++){
        set<int> aux;
        for(set<int>::iterator it = now.begin(); it != now.end(); it++){
            aux.insert(v[i] | *it);
            solution.insert(v[i] | *it);
        }
        now = aux;
        now.insert(v[i]);
        solution.insert(v[i]);
    }

    cout << solution.size() << "\n";

    return 0;   
}
