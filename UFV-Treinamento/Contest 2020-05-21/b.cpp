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
    
    vector<int> v;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i += 2)
        v.push_back(s[i] - '0');
    sort(all(v));
    cout << v[0];
    for(int i = 1; i < v.size(); i++)
        cout << "+" << v[i];
    cout << "\n";

    return 0;   
}
