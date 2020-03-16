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

void activate(vector<int> &s, vector<bool> &l){
    for(int i = 0; i < s.size(); i++)
        l[s[i]] = !l[s[i]];
}

int main(){
    optimize;

    int n, m, l;
    cin >> n >> m;

    vector<bool> lights(m, false);
    vector<vector<int>> switches(n);

    cin >> l;
    while(l--){
        int x;
        cin >> x;
        lights[x - 1] = true;
    }
    
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        while(k--){
            int y;
            cin >> y;
            switches[i].push_back(y - 1);
        }
    }

    bool possible = false, ended = false;
    int ans = 0;
    while(!ended){
        for(int i = 0; i < n; i++){
            possible |= all_of(all(lights), [](bool x){return !x;});
            if(possible || ans > 3 * n){
                ended = true;
                break;
            }
            activate(switches[i], lights);
            ans++;
        }
    }

    cout << (possible ? ans : -1) << "\n";

    return 0;   
}
