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
        cin >> n;
        vector<int> c(n);
        for(int i = 0; i < n; i++)
            cin >> c[i];

        int a = 0, b = 0, A = 0, B = 0, M = 0, l = 0, r = n - 1;
        bool turn = true;
        while(l <= r){
            if(turn){
                a = 0;
                while(a <= b && l <= r){
                    a += c[l];
                    l++;
                }
                A += a;
            }
            else{
                b = 0;
                while(b <= a && l <= r){
                    b += c[r];
                    r--;
                }
                B += b;
            }
            M++;
            turn = !turn;
        }

        cout << M << " " << A << " " << B << "\n";
    }

    return 0;   
}
