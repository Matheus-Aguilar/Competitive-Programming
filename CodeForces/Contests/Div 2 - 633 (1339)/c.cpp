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

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int max_num = -INF;
        int max_moves = 0;
        
        while(n--){
            int a;
            cin >> a;
            max_num = max(max_num, a);
            max_moves = max(max_moves, max_num - a);
        }

        if(max_moves)
            cout << (int)log2(max_moves) + 1 << "\n";
        else
            cout << 0 << "\n";
    }
    
    return 0;   
}
