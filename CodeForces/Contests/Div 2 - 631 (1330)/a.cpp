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
#define MAXN 510

using namespace std;

bool places[MAXN];

int main(){
    optimize;

    int t;
    cin >> t;
    while(t--){
        ms(places, 0);
        
        int n, x;
        cin >> n >> x;

        while(n--){
            int a;
            cin >> a;
            places[a] = true;
        }

        int i = 1;

        while(true){
            if(!places[i]){
                x--;
                if(x < 0) break;
                places[i] = true;
            }
            else{
                i++;
            }
        }

        cout << i - 1 << "\n";
    }
    
    return 0;   
}
