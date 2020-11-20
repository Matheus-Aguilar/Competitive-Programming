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
    //optimize;

    int n, now = 1, ans, dist;
    cin >> n;
    
    cout << 1 << endl;
    cin >> dist;

    if(dist == 0){
        cout << "! " << 1 << endl;
        return 0;
    }

    while(dist){
        
        cout << 2 * now << endl;
        cin >> ans;

        now *= 2;
        
        if(ans == dist + 1) 
            now++;
        dist--;
    }

    cout << "! " << now << endl;

    return 0;   
}
