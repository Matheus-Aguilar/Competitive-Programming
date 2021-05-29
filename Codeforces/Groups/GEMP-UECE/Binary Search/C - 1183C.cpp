#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

ll q, k, n, a, b;

bool check(ll x){
    return (k - x * a - (n - x) * b) > 0;
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

    cin >> q;

    while(q--){
        cin >> k >> n >> a >> b;    
        cout << binSearch(0, n + 1) << "\n";
    }

    return 0;   
}
