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

unsigned int n, a[MAXN];
vector<tuple<int, int, int>> ans;
bool possible = true;

void change(int i, int j, int k){
    a[i] = a[j] = a[k] = (a[i] ^ a[j] ^ a[k]);
    ans.push_back(make_tuple(i + 1, j + 1, k + 1));
}

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n - 2; i += 2)
        change(i, i + 1, i + 2);
    for(int i = 0; i < n - 3; i += 2)
        change(i, i + 1, n - 1);

    for(int i = 0; i < n - 1 && possible; i++)
        possible = (a[i] == a[i + 1]);
    
    if(possible){
        cout << "YES" << "\n";
        cout << ans.size() << "\n";
        
        for(int i = 0; i < ans.size(); i++)
            cout << get<0>(ans[i]) << " " << get<1>(ans[i]) << " " << get<2>(ans[i]) << "\n";
    }
    else
        cout << "NO" << "\n";
        
    return 0;   
}
