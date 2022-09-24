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
#define MAXN 250

using namespace std;

int cont[MAXN];

int main(){
    optimize;

    int t;
    cin >> t;
    while(t--){
        ms(cont, 0);
        int n, h, b = 0;
        cin >> n;
        while(n--){
            cin >> h;
            cont[h]++;
            b = max(b, h);
        }
        for(int i = 0; i < MAXN; i++){
            while(cont[i]--){
                cout << i << " \n"[(i==b)&&(cont[i]==0)];
            }
        }
    }
    
    return 0;   
}
