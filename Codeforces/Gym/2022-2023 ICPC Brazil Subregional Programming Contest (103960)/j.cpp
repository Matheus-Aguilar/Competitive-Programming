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

    int n, m = 0, j = 0, cont[11] = {0};
    cin >> n;

    for(int i = 1; i <= 9; i++)
        cont[i] = 4;
    
    cont[10] = 16;

    for(int i = 0; i < 2; i++){
        int x;
        cin >> x;

        x = min(x, 10);
        cont[x]--;
        j += x;
    }

    for(int i = 0; i < 2; i++){
        int x;
        cin >> x;

        x = min(x, 10);
        cont[x]--;
        m += x;
    }

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        x = min(x, 10);
        cont[x]--;
        m += x;
        j += x;
    }

    int ans = -1;

    for(int i = 1; i <= 10; i++){
        if(cont[i] > 0 && (m + i == 23 || (m + i < 23 && j + i > 23))){
            ans = i;
            break;
        }
    }

    cout << ans << "\n";
    
    return 0;   
}
