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

    int first = 1, last = n, dist = 1, white = 1;

    while(n > 1){
        if(n % 2 == 0){
            if(white){
                last = last - dist;
            } else {
                first = first + dist;
            }
        }
        dist *= 2;
        n = (n + 1) / 2;
        white = !white;
    }

    cout << (white ? last : first) << "\n";
    
    return 0;   
}
