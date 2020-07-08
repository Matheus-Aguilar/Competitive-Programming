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
    
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        stack<int> s;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        s.push(a[0]);
        for(int i = 1; i < n; i++){
            while(s.top() < a[i] && s.top() != a[0])
                s.pop();
            if(s.top() > a[i])
                s.push(a[i]);
        }
        cout << (s.size() == 1 ? "YES" : "NO") << "\n";
    }

    return 0;   
}
