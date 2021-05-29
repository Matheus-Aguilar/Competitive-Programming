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
        string s;
        cin >> s;
        int i = 0, j = -1, best = INF, cont[3] = {0};    
        while(j < (int)s.size()){
            if(i >= j || !cont[0] || !cont[1] || !cont[2]){
                j++;
                cont[s[j] - '1']++;
            }
            else{
                best = min(best, j - i + 1);
                cont[s[i] - '1']--;
                i++;
            }
        }

        cout << (best == INF ? 0 : best) << "\n";
    }
    
    return 0;   
}
