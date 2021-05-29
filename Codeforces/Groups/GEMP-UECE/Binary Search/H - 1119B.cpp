#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

ll n, h;
vector<ll> a;

bool check(ll k){
    
    priority_queue<ll, vector<ll>> pq;
    
    for(int i = 0; i < k; i++)
        pq.push(a[i]);
    
    ll sum = 0;

    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
        if(!pq.empty()) pq.pop();
        if(sum > h) return false;
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

    cin >> n >> h;
    a.resize(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cout << binSearch(1, n + 1) << "\n";

    return 0;   
}
