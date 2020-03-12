//(days - height % days) % days

#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long int
#define MAXN 110

using namespace std;

ll a[MAXN];
int n;
ll k;

bool check(ll d){
    ll acu = 0;
    for(int i = 0; i < n; i++)
        acu += (d - (a[i] % d)) % d;
    return acu <= k;
}

ll binarySearch(ll start, ll end){
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
    cin >> n >> k;
    ll biggest = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        biggest = max(biggest, a[i]);
    }
    cout << binarySearch(1, k + biggest + 2) << endl;
}