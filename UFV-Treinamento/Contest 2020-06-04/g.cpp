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
#define MAXN 200000

using namespace std;

int main(){
    optimize;

    int n;
    cin >> n;

    vector<ll> a(n + 1);
    vector<ll> p(n + 1, 0);

    for(int i = 1; i <= n; i++){
        cin >> a[i];
        p[i] = p[i - 1] + a[i];
    }

    set<int> s;
    multiset<ll> m;

    s.insert(0);
    s.insert(n + 1);
    m.insert(p[n]);

    for(int i = 1; i <= n; i++){
        int pos;
        cin >> pos;

        s.insert(pos);
        set<int>::iterator it1 = s.find(pos);
        set<int>::iterator it2 = it1;

        it1--, it2++;

        m.erase(m.find(p[*it2 - 1] - p[*it1]));
        m.insert(p[pos - 1] - p[*it1]);
        m.insert(p[*it2 - 1] - p[pos]);

        cout << *m.rbegin() << "\n";
    }
    
    return 0;   
}
