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

    int n, k, sum = 0, minv = 0, change = 0, pos;
    cin >> n >> k;
    
    vector<int> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
        minv = min(minv, a[i]);
    }
    
    for(int i = 0; i < k; i++)
        sum += a[i];

    pos = k - 1;

    while(sum >= 0){
        
        int diff = a[pos] - max(minv, a[pos] - sum - 1);
        
        change += diff;
        sum -= diff;
        a[pos] -= diff;
        
        pos--;
    }

    for(int i = k; i < n; i++){
        
        sum += a[i];
        sum -= a[i - k];
        
        pos = i;

        while(sum >= 0){
            int diff = a[pos] - max(minv, a[pos] - sum - 1);
        
            change += diff;
            sum -= diff;
            a[pos] -= diff;
            
            pos--;
        }
    }

    cout << change << "\n";

    for(int i = 0; i < n; i++)
        cout << a[i] << " \n"[i==n-1];

    return 0;   
}
