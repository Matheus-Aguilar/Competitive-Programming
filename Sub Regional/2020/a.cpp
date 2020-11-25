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
    
    int n, a, b;
    cin >> n >> a >> b;

    vector<long double> e(n + 1, 0.0L);

    long double l = b - a + 1;

    if(a != 0){
        for(int i = 1; i < a && i <= n; i++){
            e[i] = 1.0L;
        }
        
        long double window = 0.0;

        for(int i = a; i <= b && i <= n; i++){
            window += e[i - a];
            e[i] = 1.0L + window/l;
        }

        for(int i = b + 1; i <= n; i++){
            window -= e[i - b - 1];
            window += e[i - a];
            e[i] = 1.0L + window/l;
        }
    }
    else{
        
        long double window = 0.0;

        for(int i = 1; i <= b && i <= n; i++){
            window += e[i - 1];
            e[i] = (l/(l - 1)) * (1.0L + window/l);
        }

        for(int i = b + 1; i <= n; i++){
            window -= e[i - b - 1];
            window += e[i - 1];
            e[i] = (l/(l - 1)) * (1.0L + window/l);
        }
    }

    cout << fixed << setprecision(5) << e[n] << "\n";
    
    return 0;   
}
