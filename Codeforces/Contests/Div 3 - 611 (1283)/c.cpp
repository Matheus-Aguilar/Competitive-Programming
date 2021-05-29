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

    int n;
    cin >> n;
    vector<int> f(n);
    vector<bool> in(n, false);
    vector<bool> out(n, false);
    vector<int> a;
    vector<int> b;
    for(int i = 0; i < n; i++){
        cin >> f[i];
        --f[i];
        if(f[i] != -1) out[i] = true, in[f[i]] = true;
    }

    for(int i = 0; i < n; i++){
        if(!out[i]) a.push_back(i);
        if(!in[i]) b.push_back(i);
    }

    sort(all(a));
    sort(all(b), greater<int>());

    for(int i = 0; i < a.size(); i++){
        if(a[i] == b[i]){
            if(i == a.size() - 1)
                swap(b[i - 1], b[i]);
            else
                swap(b[i + 1], b[i]);
        }
    }

    for(int i = 0; i < a.size(); i++)
        f[a[i]] = b[i];
    
    for(int i = 0; i < n; i++)
        cout << f[i] + 1 << " ";

    cout << "\n";

    return 0;   
}
