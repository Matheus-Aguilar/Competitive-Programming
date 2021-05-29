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

    int n, c = 1;
    cin >> n;

    if(n <= 2){
        cout << 1 << "\n";
        while(n--){
            cout << 1 << " ";
        }
        cout << "\n";
    }
    else{
        vector<int> a(n + 2, 1);
        for(int i = 2; i <= n + 1; i++){
            if(a[i] == 1 && i <= (n + 1)/i){
                for(int j = i * i; j <= n + 1; j += i){
                    a[j] = 2;
                }
            }
        }
        cout << 2 << "\n";
        for(int i = 2; i <= n + 1; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
    
    return 0;   
}
