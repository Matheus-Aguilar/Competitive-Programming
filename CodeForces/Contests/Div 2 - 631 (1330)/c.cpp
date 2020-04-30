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

    int n, m;
    cin >> n >> m;
    
    vector<int> l(m);
    vector<int> p(m);

    for(int i = 0; i < m; i++)
        cin >> l[i];

    int prev = l[0];
    int remainder = n - l[0];
    ll sum = 0;

    for(int i = 1; i < m; i++) sum += l[i];

    int pos = 1;
    p[0] = pos;
    
    if(sum < remainder){
        cout << -1 << "\n";
        return 0;
    }

    for(int i = 1; i < m; i++){
        if(sum < remainder){
            cout << -1 << "\n";
            return 0;
        }
        else{
            int disc = min(prev - 1LL, sum - remainder);
            pos += prev;
            pos -= disc;
            if(pos + l[i] - 1 > n){
                cout << -1 << "\n";
                return 0;
            }
            p[i] = pos;
            prev = l[i];
            sum -= prev;
            remainder = n - (pos + l[i] - 1);
        }
    }

    for(int i = 0; i < m; i++)
        cout << p[i] << " ";
    cout << "\n";

    return 0;   
}
