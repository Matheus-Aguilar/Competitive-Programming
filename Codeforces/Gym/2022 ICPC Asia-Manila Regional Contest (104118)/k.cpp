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
 
const string qwerty = "QWERTYUIOPASDFGHJKLZXCVBNM";
string s = "";
int correct = 0;
 
void solve() {
	for(int i = 0; i < 3; i++){
		string aux;
		cin >> aux;
		s += aux;
	}
 
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '*'){
			int pos = qwerty[i] - 'A';
			correct |= (1 << pos);
		}
	}
 
	int q;
	cin >> q;
 
	while(q--){
		cin >> s;
 
		int mask = 0;
 
		for(int i = 0; i < s.size(); i++){
			int pos = s[i] - 'A';
			mask |= (1 << pos);
		}
 
		cout << (mask == correct ? "POSSIBLE" : "IMPOSSIBLE") << "\n";
	}
}
 
int main() {
 
	optimize;
	
    solve();
 
	return 0;
}