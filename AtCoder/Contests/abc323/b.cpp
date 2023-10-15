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

    vector<string> s(n);

    for(int i = 0; i < n; i++)
        cin >> s[i];

    vector<pii> w(n, make_pair(0, 0));

    for(int i = 0; i < n; i++){
        w[i].second = i + 1;
        for(int j = 0; j < n; j++){
            if(s[i][j] == 'o'){
                w[i].first--;
            }
        }
    }

    sort(all(w));

    for(int i = 0; i < n; i++)
        cout << w[i].second << " \n"[i+1==n];
    
    return 0;   
}
