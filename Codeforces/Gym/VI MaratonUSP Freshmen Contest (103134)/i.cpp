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

    const int p[12] = {15, 12, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int n, i = 0;
    cin >> n;

    vector<int> ans;

    while(n > 0){
        while(p[i] <= n){
            ans.push_back(i + 1);
            n -= p[i];
        }
        i++;
    }

    cout << ans.size() << "\n";
    
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";
    
    return 0;   
}
