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
    vector<bool> a(1000010, false);
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        a[p] = true;
    }

    int i = 1, j = 1000000;

    int cont = 0;

    while(n){
        i++, j--, cont++;
        if(a[i]){
            a[i] = false;
            n--;
        }
        if(a[j]){
            a[j] = false;
            n--;
        }
    }

    cout << cont << "\n";

    return 0;   
}
