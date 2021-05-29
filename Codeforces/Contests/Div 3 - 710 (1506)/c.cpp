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
        string a, b;
        cin >> a >> b;

        int best = a.size() + b.size();

        for(int i = 0; i < a.size(); i++){
            for(int j = 1; j <= a.size() - i; j++){
                
                const string s = a.substr(i, j);
                
                if(b.find(s) != string::npos){
                    best = min(best, (int)a.size() - (int)s.size() + (int)b.size() - (int)s.size());
                }
            }   
        }

        cout << best << "\n";
    }
    
    return 0;   
}
