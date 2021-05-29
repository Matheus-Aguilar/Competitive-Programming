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
    
    string s;
    cin >> s;

    vector<vector<int>> c(26);
    for(int i = 0; i < s.size(); i++)
        c[(int)(s[i] - 'a')].push_back(i);

    int n;
    cin >> n;

    while(n--){
        string a, spell = "";
        cin >> a;

        int pos = 0;

        for(int i = 0; i < a.size(); i++){
            vector<int>::iterator it = lower_bound(all(c[(int)(a[i] - 'a')]), pos);
            if(it == c[(int)(a[i] - 'a')].end())
                break;
            pos = *it + 1;
            spell += a[i];
        }
        cout << (spell == "" ? "IMPOSSIBLE" : spell) << "\n";
    }

    return 0;   
}
