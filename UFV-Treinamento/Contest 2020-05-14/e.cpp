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
    vector<int> a(n);
    set<int> s;
    multiset<int> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int l = -1, r = -1;
    for(int i = 0; i < n; i++){
        s.insert(a[i]);
        if(s.size() == k){
            r = i + 1;
            break;
        }
    }

    if(r == -1){
        cout << -1 << " " << -1 << "\n";
        return 0;
    }

    s.clear();

    for(int i = r - 1; i >= 0; i--){
        s.insert(a[i]);
        if(s.size() == k){
            l = i + 1;
            break;
        }
    }

    cout << l << " " << r << "\n";

    return 0;   
}
