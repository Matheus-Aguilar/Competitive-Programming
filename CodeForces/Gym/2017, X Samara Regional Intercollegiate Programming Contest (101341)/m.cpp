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

    int n, m = 0;
    cin >> n;

    vector<pii> a(n);
    vector<int> alive;
    vector<pii> kills;

    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(all(a));

    bool ans = true;

    for(int i = 0; i < n && ans; i++){
        if(alive.size() < a[i].first)
            ans = false;
        else{
            while(a[i].first--){
                kills.emplace_back(a[i].second, alive.back());
                alive.pop_back();
            }
            alive.push_back(a[i].second);
        }
    }

    if(!ans)
        cout << "NO" << "\n";
    else{
        cout << "YES" << "\n";
        for(int i = 0; i < kills.size(); i++)
            cout << kills[i].first << " " << kills[i].second << "\n";
    }

    return 0;   
}
