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

    int n, vs, vb, vl;
    cin >> n >> vs >> vb >> vl;

    n++;

    vector<int> cell(n, -1);

    int p1 = 0, p2 = 0, p3 = 0, p = 0, k = 4 * n;
    ll ans = 3000000000;
    
    for(int i = 1; i <= k; i++){
        if(p == 0){
            
            p1 = (p1 + vs) % n;
            
            if(cell[p1] == -1){
                cell[p1] = 0;
            }
            else if(cell[p1] != 0 && p1 != 0){
                ans = i;
                break;
            }
        }
        else if(p == 1){
            
            p2 = (p2 + vb) % n;
            
            if(cell[p2] == -1){
                cell[p2] = 1;
            }
            else if(cell[p2] != 1 && p2 != 0){
                ans = i;
                break;
            }
        }
        else{
            
            p3 = (p3 + vl) % n;
            
            if(cell[p3] == -1){
                cell[p3] = 2;
            }
            else if(cell[p3] != 2 && p1 != 0){
                ans = i;
                break;
            }
        }

        p = (p + 1) % 3;
    }

    cout << ans << "\n";

    return 0;   
}
