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

    int n;
    cin >> n;

    deque<char> d;

    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        d.push_back(c);
    }

    while(!d.empty() && d.front() == 'V'){
        d.pop_front();
    }

    while(!d.empty() && d.back() == 'V'){
        d.pop_back();
    }

    int ans = 0;

    while(!d.empty()){
        if(d.front() == 'V')
            ans++;
        d.pop_front();
    }

    cout << ans << "\n";
    
    return 0;   
}
