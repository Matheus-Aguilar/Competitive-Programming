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

    vector<int> v(1, 1);
    for(int i = 1;  i < 30; i++)
        v.push_back(2 * v[i - 1] + 1);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 1; i < v.size(); i++){
            if(n % v[i] == 0){
                cout << n/v[i] << "\n";
                break;
            }
        }
    }
    
    return 0;   
}
