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
#define MAXN 100100

using namespace std;

ll n, l[MAXN], p[MAXN], sz = 0;

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> l[i];

    p[0] = 0;

    for(int i = 0; i < n - 1; i++)
        p[i + 1] = p[i] + l[i];

    sz = p[n - 1] + l[n - 1];

    if(sz % 2 != 0){
        cout << "N" << "\n";
        return 0;
    }

    int cont = 0;

    for(int i = 0; i < n && cont < 2; i++){
        if(binary_search(p, p + n, (p[i] + sz / 2))){
            cont++;
        }
    }

    cout << (cont >= 2 ? "Y" : "N") << "\n";

    return 0;   
}
