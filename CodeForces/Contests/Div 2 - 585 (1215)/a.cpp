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

int solveMax(int a1, int a2, int k1, int k2, int n){
    if(k1 > k2){
        swap(k1, k2);
        swap(a1, a2);
    }
    while(n >= k1 && a1 > 0){
        n -= k1;
        a1--;
    }
    while(n >= k2 && a2 > 0){
        n -= k2;
        a2--;
    }
    return a1 + a2;
}

int solveMin(int a1, int a2, int k1, int k2, int n){
    if(k1 < k2){
        swap(k1, k2);
        swap(a1, a2);
    }

    n = max(0, n - a1 * (k1 - 1));
    n = max(0, n - a2 * (k2 - 1));

    return a1 + a2 - n;
}

int main(){
    optimize;

    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    cout << (a1 + a2) - solveMin(a1, a2, k1, k2, n) << " " << (a1 + a2) - solveMax(a1, a2, k1, k2, n) << "\n";
    
    return 0;   
}
