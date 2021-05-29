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
        int k, n;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> p(n, 0);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 1; i < n - 1; i++){
            if(a[i - 1] < a[i] && a[i] > a[i + 1]){
                p[i] = 1;
            }
        }

        int l = 0;
        int bestL = 0;
        int best = 0;
        for(int i = 1; i < k - 1; i++)
            best += p[i];
        int now = best;

        for(int i = k; i < n; i++){
            now -= p[l + 1];
            now += p[i - 1];

            if(now > best){
                best = now;
                bestL = l + 1;
            }
            l++;
        }

        cout << best + 1 << " " << bestL + 1 << "\n";
    }

    return 0;   
}
