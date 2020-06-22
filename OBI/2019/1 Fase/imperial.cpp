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

    vector<int> v(n);
    vector<int> c(n + 1, 0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        c[v[i]]++;
    }

    int best = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) 
                continue;
            int sum = 0, now = i;
            for(int k = 0; k < n; k++){
                if(v[k] == now){
                    sum++;
                    now = (i == now ? j : i);
                }
            }
            best = max(best, sum);
        }
    }

    cout << best << "\n";

    return 0;   
}
