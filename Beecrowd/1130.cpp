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

int g[10001];
int st[300];

void preCalc(){
    g[0] = 0;
    g[1] = g[2] = 1;

    for(int i = 3; i <= 10000; i++){
        ms(st, false);
        st[g[i - 3]] = true;
        if(i - 4 >= 0) st[g[i - 4]] = true;
        for(int j = 0; j <= (i - 5)/2; j++)
            st[g[j] ^ g[i - j - 5]] = true;
        for(int j = 0; j < 300; j++){
            if(!st[j]){
                g[i] = j;
                break;
            }
        }
    }
}

int main(){
    optimize;
    
    preCalc();

    int n;

    while(cin >> n && n){
        
        string s;
        cin >> s;
        
        vector<int> x;
        vector<int> v;
        
        for(int i = 0; i < s.size(); i++)
            if(s[i] == 'X')
                x.push_back(i);

        bool ans = false;

        for(int i = 1; i < x.size() && !ans; i++)
            if(x[i] - x[i - 1] <= 2)
                ans = true;
        
        if(ans)
            cout << "S" << "\n";
        else if(x.size() == 0)
            cout << (g[n] ? "S" : "N") << "\n";
        else{
            v.push_back(max(x[0] - 2, 0));
            for(int i = 1; i < x.size(); i++)
                v.push_back(max(x[i] - x[i - 1] - 5, 0));
            v.push_back(max(n - x.back() - 3, 0));

            int xr = 0;
            for(int i = 0; i < v.size(); i++)
                xr ^= g[v[i]];

            cout << (xr ? "S" : "N") << "\n";
        }
    }

    return 0;   
}
