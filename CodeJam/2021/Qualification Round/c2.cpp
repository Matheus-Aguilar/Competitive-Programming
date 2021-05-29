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

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){

        int n, c;

        cin >> n >> c;

        vector<int> a(n);
        vector<int> sum(n - 1, 1);

        iota(all(a), 1);

        c -= n - 1;

        for(int i = n - 2; i >= 0 && c > 0; i--){
            if((n - i - 1) <= c){
                c -= n - i - 1;
                sum[i] += n - i - 1;
            }
            else{
                sum[i] += c;
                c = 0;
            }
        }

        for(int i = n - 2; i >= 0 && c == 0; i--){
            reverse(a.begin() + i, a.begin() + i + sum[i]);
        }

        cout << "Case #" << t << ": ";

        if(c != 0){
            cout << "IMPOSSIBLE" << "\n";
        }
        else{
            for(int i = 0; i < n; i++)
                cout << a[i] << " \n"[i==n-1];
        }
    }
        
    return 0;   
}
