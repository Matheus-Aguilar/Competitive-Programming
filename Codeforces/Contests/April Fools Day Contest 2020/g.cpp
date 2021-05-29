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
    vector<int> v;
    while(cin >> n){
        v.push_back(n);
    }

    while(v.size() > 0){
        int var = v.back();
        v.pop_back();
        long double a = sqrt(abs(var));
        long double b = 5 * (pow(var, 3));

        if(400 >= a + b)
            printf("f(%d) = %.2Lf\n", var, a + b);
        else
            printf("f(%d) = MAGNA NIMIS!\n", var);
        
    }
    
    return 0;   
}
