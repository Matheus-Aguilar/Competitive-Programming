#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;

    int n;
    cin >> n;

    vector<ll> d(n, 0);
    vector<ll> a(n + 1, 0);
    
    for(int i = 0; i < n; i++){
        cin >> d[i];
        a[i + 1] = a[i] + d[i]; 
    }
    
    ll sum  = 0;
    ll best = 0;

    for(int i = n - 1; i >= 0; i--){
        sum += d[i];
        if(binary_search(a.begin(), a.begin() + i + 1, sum)) 
            best = sum;
    }

    cout << best << "\n";

    return 0;   
}

