#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;


ll n, k;
vector<ll> a;

bool check(ll x){
    ll newMedian = a[n/2] + x;
    ll operations = k - x;
    for(int i = n/2 + 1; i < n; i++){
        operations -= max(newMedian - a[i], 0LL);
        if(operations < 0) return false;
    }
    return true;
}

ll binSearch(ll start, ll end){
    while(start < end){
        ll middle = start + (end - start)/2;
        if(check(middle))
            start = middle + 1;
        else
            end = middle;
    }
    return start - 1;
}

int main(){
    optimize;

    cin >> n >> k;
    a.resize(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    cout << binSearch(0, k + 1) + a[n/2] << "\n";

    return 0;   
}
