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



/*

X -> 2^i + X (impar)

00
01
10
11

000
001
010
011

100
101
110
111

7 = 2

1 = 1
2 = 1
4 = 1

*/

int calc(int x) {
    vector<int> v;

    while(x > 0){
        v.push_back(x & 1);
        x >>= 1;
    }

    reverse(all(v));

    int sum = 0;

    for(int i = 0; i < v.size(); i += 2){
        sum += v[i];
    }

    return sum;
}

int main(int argc, char **argv){
    optimize;

    int n = atoi(argv[1]);
    int sum = 0;

    for(int i = 0; i <= n; i++){
        sum += calc(i);
        cout << i << ": " << calc(i) << " " << sum << "\n";
    }

    return 0;
}
