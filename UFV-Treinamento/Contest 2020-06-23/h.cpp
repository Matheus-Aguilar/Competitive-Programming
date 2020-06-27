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

    int n, cont = 0;
    string last, now;

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> now;
        if(i == 0 || last[1] == now[0])
            cont++;
        last = now;
    }

    cout << cont << "\n";
    
    return 0;   
}
