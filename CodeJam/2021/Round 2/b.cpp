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

int n;

int bt(int i, int sum, int cont){
    
    if(sum == n)
        return cont;
    
    int best = 0;
    
    for(int j = 2; sum + i * j <= n; j++)
        best = max(best, bt(i * j, sum + i * j, cont + 1));

    return best;
}

int main(){
    optimize;

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){
        
        cin >> n;

        int best = 0;

        for(int i = 3; i <= n; i++){
            best = max(best, bt(i, i, 1));
        }

        cout << "Case #" << t << ": " << best << "\n";
    }
    
    return 0;   
}
