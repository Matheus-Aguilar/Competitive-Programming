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

    int n, a;
    cin >> n;

    if(n == 1){
        cout << "N" << "\n";
        return 0;
    }

    vector<int> c(200200, 0);

    for(int i = 0; i < n; i++){
        cin >> a;
        c[a]++;
    }

    for(int i = 0; i < 200000; i++){
        c[i + 1] += c[i] / 2;
        c[i] %= 2;
    }

    int cont = count_if(all(c), [](int x){ return x == 1; });

    cout << (cont <= 2 ? "Y" : "N") << "\n";

    return 0;   
}