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
        int n, k, i, j, l, s;
        cin >> n >> k;
        i = n - 2;
        j = n - 1;
        l = 1;
        while(l < k){
            i--;
            k -= l;
            l++;
        }

       
        while(--k){
            j--;
        }

        for(int a = 0; a < n; a++){
            if(a == i || a == j)
                cout << 'b';
            else
                cout << 'a';
        }
        cout << "\n";
    }
    
    return 0;   
}