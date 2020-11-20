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

    int n, l;
    cin >> n >> l;

    vector<int> cont(l + 1, 0);

    while(n--){
        int x, y;
        cin >> x >> y;
        cont[y]++;
    }

    for(int i = 0; i < l; i++){
        if(cont[i] == 0){
            cout << i << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
    
    return 0;   
}
