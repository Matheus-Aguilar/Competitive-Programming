#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;
    
    int v, n, p;
    cin >> v >> n;

    p = v * n;

    for(long double i = 1; i <= 9; i++){
        cout << (int)ceil(p * i/10.0) << (i != 9 ? ' ': '\n');
    }

    return 0;   
}
