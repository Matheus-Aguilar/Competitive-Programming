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
    
    int n; 
    cin >> n;
    vector<int> p(n + 1);

    for(int i = 1; i <= n; i++)
        cin >> p[i];

    p[0] = 0;
    sort(all(p));

    for(int i = 0; i < n; i++){
        if(p[i + 1] - p[i] > 8){
            cout << "N" << "\n";
            return 0;
        }
    }

    cout << "S" << "\n";
         
    return 0;   
}
