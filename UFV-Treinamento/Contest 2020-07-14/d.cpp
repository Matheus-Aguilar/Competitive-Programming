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

    int n, q;
    cin >> n;

    vector<string> f(n);
    unordered_map<string, int> cont;
    unordered_map<string, string> rep;

    for(int i = 0; i < n; i++)
        cin >> f[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < f[i].size(); j++){
            for(int k = j; k < f[i].size(); k++){
                string sub = f[i].substr(j, k - j + 1);
                if(rep[sub] != f[i])
                    cont[sub]++;
                rep[sub] = f[i];
            }
        }
    }

    cin >> q;

    while(q--){
        string s;
        cin >> s;
        if(cont[s] > 0)
            cout << cont[s] << " " << rep[s] << "\n";
        else
            cout << 0 << " " << "-" << "\n";
    }

    return 0;   
}
