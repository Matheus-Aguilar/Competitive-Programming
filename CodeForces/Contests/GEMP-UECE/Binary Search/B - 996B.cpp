#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long int
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

ll n;
vector<ll> a;

bool check(ll x){

    ll minutes = x - (x % n);

    for(int i = 0; i < a.size(); i++){
        if(x % n >= (ll)i){
            if(a[i] - minutes - i <= 0LL) 
                return true;
        }
        else{
            if(a[i] - minutes - i + n <= 0LL) 
                return true;
        }
    }
    
    return false;
}

ll binarySearch(ll start, ll end){
    while(start < end){

        ll middle = start + (end - start)/2;

        if(check(middle))
            end = middle;
        else
            start = middle + 1;
    }

    return start;
}

int main(){
    optimize;

    cin >> n;
    a.resize(n);

    ll sum = 0;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }

    ll firstMinute = binarySearch(0, sum + 1);

    cout << firstMinute % n + 1 << "\n";

    return 0;   
}
