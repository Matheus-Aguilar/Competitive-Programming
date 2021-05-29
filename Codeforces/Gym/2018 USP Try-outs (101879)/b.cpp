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

    int n, k = -1;
    cin >> n;

    vector<int> l(n);
    vector<int> cnt(n, 0);

    for(int i = 0; i < n; i++){
        cin >> l[i];
    }
    
    for(int i = 2; i <= n && k == -1; i++){
        
        if(n % i != 0) 
            continue;

        fill(cnt.begin(), cnt.begin() + i, 0);
    
        for(int j = 0; j < n; j++)
            cnt[l[j] % i]++;

        if(all_of(cnt.begin(), cnt.begin() + i, [=](int x){ return x == n / i; }))
            k = i;
    }

    cout << k << "\n";

    return 0;   
}
