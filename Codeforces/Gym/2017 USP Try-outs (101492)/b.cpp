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

    if(n % 4 == 1 || n % 4 == 2){
        cout << -1 << "\n";
    }
    else{
        if(n % 4 == 3)
            cout << "++-";

        for(int i = 0; i < n - 3; i += 4)
            cout << "+--+";
        
        cout << "\n";
    }

    return 0;   
}
