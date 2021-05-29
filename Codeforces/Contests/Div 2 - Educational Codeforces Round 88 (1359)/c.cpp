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

ll h, c, t;

long double f(long double i){
    return abs((h * i + c * i + h)/(2.0 * i + 1) - t);
}

 
int ternarySearch(int start, int end){
    while(start < end){
        int m1 = start + (end - start)/3;
        int m2 = end - (end - start)/3;
 
        long double f1 = f(m1);
        long double f2 = f(m2);
 
        if(f1 > f2)
            start = m1 + 1;
        else
            end = m2 - 1;
    }
    return start;
}

int main(){
    optimize;

    int T;
    cin >> T;
    while(T--){
        cin >> h >> c >> t;
        if(t >= h)
            cout << 1 << "\n";
        else if(t <= (h + c)/2)
            cout << 2 << "\n";
        else{
            cout << 2 * ternarySearch(0LL, 1000000LL) + 1 << "\n";
        }
    }
    
    return 0;   
}
