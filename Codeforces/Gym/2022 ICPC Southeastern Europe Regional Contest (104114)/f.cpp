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

    vector<vector<int>> a(n, vector<int>(n));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }   
    }
    
    int sum = 0;
    vector<pii> matches;

    for(int i = n - 1; i > 0; i--){
        int best = 0;

        for(int j = 1; j < i; j++){
            if(a[i][best] < a[i][j]){
                best = j;
            }
        }

        matches.emplace_back(i + 1, best + 1);
        sum += a[i][best];

        for(int j = 0; j < n; j++){
            a[best][j] = max(a[best][j], a[i][j]);
            a[j][best] = a[best][j];
        }
    }

    cout << sum << "\n";

    for(int i = 0; i < matches.size(); i++)
        cout << matches[i].first << " " << matches[i].second << "\n";

    return 0;   
}
