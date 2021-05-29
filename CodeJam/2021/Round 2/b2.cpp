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

int solve(int i){
    
    int best = 1;
    
    for(int j = 3; j <= i; j++){
        if(i % i == 0 && (i / j - 1 > 1))
            best = max(best, 1 + solve(i / j - 1));
    }

    return best;
}

int main(){
    optimize;

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){
        
        cin >> n;

        int best = 1;

        for(int i = 3; i <= n; i++){
            if(n % i == 0 && (n / i - 1 > 1))
                best = max(best, 1 + solve(n / i - 1));
        }

        cout << "Case #" << t << ": " << best << "\n";
    }
    
    return 0;   
}
