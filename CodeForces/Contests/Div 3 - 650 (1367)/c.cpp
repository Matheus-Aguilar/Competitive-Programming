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
        int n, k, cont = 0, last = -1;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> nxt(n);
    
        nxt[n - 1] = (s[n - 1] == '1' ? n - 1: -1);
        for(int i = n - 2; i >= 0; i--)
            nxt[i] = (s[i] == '1' ? i : nxt[i + 1]);
        for(int i = 0; i < n; i++){
            if(s[i] == '1')
                last = i;
            else{
                if((last == -1 || i - last > k) && (nxt[i] == -1 || nxt[i] - i > k)){
                    cont++;
                    last = i;
                }
            }
        }
        cout << cont << "\n";
    }
    
    return 0;   
}
