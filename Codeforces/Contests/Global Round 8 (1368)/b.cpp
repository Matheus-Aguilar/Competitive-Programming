#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<in't', int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

ll prod(ll v[]){
    ll ans = 1;
    for(int i = 0; i < 10; i++)
        ans *= v[i];
    return ans;
}

int main(){
    optimize;
    
    ll k;
    char c[10] = {'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};
    ll v[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    
    cin >> k;

    int i = 0;

    while(prod(v) < k){
        v[i]++;
        i = (i + 1) % 10;
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < v[i]; j++){
            cout << c[i];
        }
    }
    
    cout << "\n";

    return 0;   
}
