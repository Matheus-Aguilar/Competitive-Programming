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
#define MAXN 100100

using namespace std;

ll n,m;
ll a[MAXN];
set<pair<ll, int>> pq;
 
void fix(ll v, int pos){
	if(pos < 0 || pos >= n || a[pos] > v || v - a[pos] <= m)
		return;
	pq.erase(make_pair(a[pos], pos));
	a[pos] = v - m;
	pq.emplace(a[pos], pos);
}

int main(){
    optimize;

    cin >> n >> m;
 
	for(int i = 0; i < n; i++){
		cin >> a[i];
		pq.emplace(a[i], i);
	}
 
	while(!pq.empty()){
		auto p = *pq.begin();
		ll v = p.first;
		int pos = p.second;
 
		pq.erase(p);
 
		fix(v, pos + 1);
		fix(v, pos - 1);
	}
 
	for(int i = 0; i < n; i++)
		cout << a[i] << " \n"[i+1==n];
    
    return 0;   
}
