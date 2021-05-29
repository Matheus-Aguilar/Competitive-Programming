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
    
    ll p, l, r;
    cin >> l >> r >> p;

    if(l > r){
        cout << (((l * p + 99) / 100) <= r ? "Ambidextrous" : "Left-handed") << "\n";
    }
    else if(r > l){
        cout << (((r * p + 99) / 100) <= l ? "Ambidextrous" : "Right-handed") << "\n";
    }
    else{
        cout << "Ambidextrous" << "\n";
    }

    return 0;   
}
