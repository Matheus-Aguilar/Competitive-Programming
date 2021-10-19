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

const string s[3] = {"First", "Second", "Third"};

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        pair<int, string> p[3];

        for(int i = 0; i < 3; i++){
            cin >> p[i].first;
            p[i].second = s[i];
        }

        sort(p, p + 3);
        cout << p[0].second << "\n";
    }
    
    return 0;   
}
