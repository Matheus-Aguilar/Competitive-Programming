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

    int k, n;
    map<string, int> cont, last;

    cin >> n >> k;
    cin.ignore();

    vector<string> s(3 * n);

    for(int i = 0; i < 3 * n; i++){
        
        getline(cin, s[i]);

        cont[s[i]]++;
        last[s[i]] = i;
    }

    vector<tuple<int, int, string>> t(3 * n);

    for(int i = 0; i < 3 * n; i++){
        t[i] = make_tuple(cont[s[i]], last[s[i]], s[i]);
    }

    sort(all(t));
    t.resize(unique(all(t)) - t.begin());
    reverse(all(t));
    
    for(int i = 0; i < k && i < t.size(); i++)
        cout << get<2>(t[i]) << "\n";

    return 0;   
}
