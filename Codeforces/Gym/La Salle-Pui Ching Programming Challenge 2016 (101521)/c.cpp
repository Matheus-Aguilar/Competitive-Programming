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
    ll r, k;

    cin >> n >> r >> k;

    vector<int> a;
    vector<int> d;

    for(ll i = 1; i * i <= k && i <= r; i++){
        if(k % i == 0){
            d.push_back(i);
            if(k / i != i) d.push_back(k / i);
        }
    }

    sort(all(d));

    if(k < r){
        
        for(int i = 1, j = 0; a.size() < n; i++){
            if(k % i == 0){
                a.push_back(i);
            }
        }

        if(a.back() != k)
            a[0] = k;
        
        if(a.size() < n){
            cout << -1 << "\n";
        }
        else{
            for(int i = 0; i < n; i++)
                cout << a[i] << " \n"[i==n-1];
        }
    }
    
    return 0;   
}
