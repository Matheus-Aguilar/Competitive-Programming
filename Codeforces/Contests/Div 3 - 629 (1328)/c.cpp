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
        string a, b, x;
        cin >> n >> x;
        a.resize(n);
        b.resize(n);

        bool equals = true;

        a[0] = b[0] = '1';
        for(int i = 1; i < x.size(); i++){
            if(x[i] == '0'){
                a[i] = b[i] = '0';
            }
            else if(x[i] == '2'){
                if(equals){
                    a[i] = b[i] = '1';
                }
                else{
                    a[i] = '2';
                    b[i] = '0';
                }
            }
            else{
                if(equals){
                    equals = false;
                    a[i] = '0';
                    b[i] = '1';
                }
                else{
                    a[i] = '1';
                    b[i] = '0';
                }
            }
        }

        cout << a << "\n" << b << "\n";
    }

    return 0;   
}
