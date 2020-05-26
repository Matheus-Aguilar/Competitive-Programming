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

    int n, bl, br;
    ll best = -INFLL;
    map<int, int> l;
    map<int, int> r;
    
    cin >> n;
    
    vector<ll> a(n + 1);
    vector<ll> prefix(n + 1, 0);
    
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        prefix[i] = max(prefix[i - 1], prefix[i - 1] + a[i]);
    }
    
    for(int i = 1; i <= n; i++)
        r[a[i]] = i;
    for(int i = n; i >= 1; i--)
        l[a[i]] = i;
    for(int i = 1; i <= n; i++){
        if(l[a[i]] != r[a[i]] && best < prefix[r[a[i]] - 1] - prefix[l[a[i]]] + 2LL * a[i]){
            best = prefix[r[a[i]] - 1] - prefix[l[a[i]]] + 2LL * a[i];
            bl = l[a[i]];
            br = r[a[i]];
        }
    }

    int k = 0;
    vector<int> cut;

    for(int i = 1; i < bl; i++){
        k++;
        cut.push_back(i);
    }
    for(int i = bl + 1; i < br; i++){
        if(a[i] < 0){
            k++;
            cut.push_back(i);
        }
    }
    for(int i = br + 1; i <= n; i++){
        k++;
        cut.push_back(i);
    }

    cout << best << " " << k << "\n";
    for(int i:cut) cout << i << " ";
    if(k) cout << "\n";

    return 0;   
}
