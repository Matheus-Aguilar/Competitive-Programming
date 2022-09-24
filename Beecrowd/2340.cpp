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
    int melhor = -1;
    long double maior = -1.0L;

    cin >> n;
    for(int i = 0; i < n; i++){
        int d, c;
        cin >> d >> c;
        long double t = log2l(d) * c;
        if(t > maior){
            maior = t;
            melhor = i;
        }
    }

    cout << melhor << "\n";

    return 0;   
}
