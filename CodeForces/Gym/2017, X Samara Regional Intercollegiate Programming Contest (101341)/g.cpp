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

    int n, m;
    cin >> n;

    vector<int> love(n + 1, 0);
    vector<string> name(n + 1);
    
    for(int i = 1; i <= n; i++)
        cin >> name[i];

    cin >> m;

    while(m--){
        int a, b;
        cin >> a >> b;
        love[a] = love[b] + 1;
        name[a] = name[b];
    }

    while(love[1]--)
        cout << "I_love_";
    cout << name[1] << "\n";

    return 0;   
}
