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

    int n, sum = 0, cont = 0;
    int x, y;
    char aux;    

    cin >> n;

    for(int i = 0; i <= n; i++){

        cin >> aux >> x >> aux >> y;
        sum += 100 * x + y;

        if(i > 0 && sum % 100 != 0){
            cont++;
        }
    }

    cout << cont << "\n";
    
    return 0;   
}
