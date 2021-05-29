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
        int n;
        string a = "1", b;

        cin >> n >> b;

        char c = '1';

        for(int i = 1; i < n; i++){
            if(b[i] == '0'){
                if(b[i - 1] == '0'){
                    a += (a[i - 1] == '0' ? '1' : '0');
                }
                else{
                    a += (a[i - 1] == '0' ? '0' : '1');
                }
            }
            else{
                if(b[i - 1] == '0'){
                    a += '1';
                }
                else{
                    a += (a[i - 1] == '1' ? '0' : '1');
                }
            }
        }

        cout << a << "\n";
    }
    
    return 0;   
}
