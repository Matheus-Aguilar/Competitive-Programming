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

ll cont[31][31];

void solve(int x){
    
    if(x < 0) return;
    
    solve(x - 1);
    solve(x - 2);
}

void precalc(){
    for(int i = 0; i <= 30; i++)
        cont[i][i] = 1;
    solve(30);
}

int main(){
    optimize;

    precalc();

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){

        int n, a, b, ans = -1;
        bool ok = true;

        cin >> n >> a >> b;

        vector<int> u(n, 0);

        for(int i = 0; i < n; i++)
            cin >> u[i];



        if(ok)
            cout << "Case #" << t << ": " << (int)u.size() + 1 << "\n"; 
        else
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << "\n"; 
    }
    
    return 0;   
}
