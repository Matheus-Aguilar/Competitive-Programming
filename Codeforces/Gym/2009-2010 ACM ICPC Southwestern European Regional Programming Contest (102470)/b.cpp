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
    bool first = true;

    while(cin >> n && n){
        
        if(!first) cout << "\n";
        first = false;
        
        string op;
        int m;

        int p1 = 0, p2 = 0;
        
        while(n--){
            cin >> op >> m;
            if(op == "DROP"){
                cout << "DROP 1 " << m << "\n";
                p1 += m;
            }
            else{
                if(p2 >= m){
                    cout << "TAKE 2 " << m << "\n";
                    p2 -= m;
                }
                else{
                    if(p2) cout << "TAKE 2 " << p2 << "\n";
                    cout << "MOVE 1->2 " << p1 << "\n";
                    cout << "TAKE 2 " << m - p2 << "\n";
                    p2 = p1 - m + p2; 
                    p1 = 0;
                }
            }
        }
    }
    
    return 0;   
}
