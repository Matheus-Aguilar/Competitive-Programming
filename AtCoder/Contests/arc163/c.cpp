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

        if(n == 1){
            cout << "Yes" << "\n";
            cout << 1 << "\n";
            continue;
        }

        if(n == 2){
            cout << "No" << "\n";
            continue;
        }

        vector<int> a(n);

        for(int i = 1; i < n; i++){
            a[i - 1] = i * (i + 1);
        }

        a[n - 1] = n;

        bool ok = true;

        for(int i = 0; i < n - 1 && ok; i++){
            ok = (a[n - 1] != a[i]);
        }

        if(!ok){
            a[n - 2] = n - 1;

            for(int i = 0; i < n; i++)
                a[i] *= 2;
            
            a[n - 1] = 2;
        }

        cout << "Yes" << "\n";

        for(int i = 0; i < n; i++){
            cout << a[i] << " \n"[i+1==n];
        }
    }
    
    return 0;   
}
