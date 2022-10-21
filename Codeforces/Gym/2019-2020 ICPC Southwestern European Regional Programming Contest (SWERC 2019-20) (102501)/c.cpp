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
#define MAXN 1000100

using namespace std;

int mex = 0;
bool vis[MAXN];

int main(){
    optimize;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s[0] != '-' && s.size() < 7)
            vis[stoi(s)] = true;
        while(vis[mex])
            mex++;
    }

    cout << mex << "\n";
    
    return 0;   
}
