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

bool check(int a[4]){
    return (a[0] + a[1]) == (a[2] + a[3]);
}

int main(){
    optimize;
    
    bool ans = false;
    int a[4];

    for(int i = 0; i < 4; i++)
        cin >> a[i];

    sort(a, a + 4);

    do{
        ans |= check(a);
    } while(next_permutation(a, a + 4));

    cout << (ans ? "YES" : "NO") << "\n";

    return 0;   
}
