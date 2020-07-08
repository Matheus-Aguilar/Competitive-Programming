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
    
    int n, best = -INF, val = INF;
    cin >> n;
    
    vector<int> a(n), cont(n + 1, 0), record(n + 1, 0);
    set<int> s;

    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++){
        set<int>::iterator it = s.lower_bound(a[i]);
        if(it == s.end())
            record[a[i]] = 1;
        else if(*it == *s.rbegin())
            cont[*it]++;
        s.insert(a[i]);
    }

    for(int i = 1; i <= n; i++){
        if(best < cont[i] - record[i]){
            best = cont[i] - record[i];
            val = i;
        }
        else if(best == cont[i] - record[i] && val > i)
            val = i;
    }

    cout << val << "\n";

    return 0;   
}
