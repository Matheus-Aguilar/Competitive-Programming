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
        
        vector<int> a(2 * n);
        vector<pii> b(n);

        vector<bool> v(2 * n + 1, false);
        vector<int> c(n);

        for(int i = 0; i < n; i++){
            cin >> b[i].first;
            a[2 * i] = b[i].first;
            v[b[i].first] = true;
            b[i].second = i;
        }

        for(int i = 1, j = 0; i <= 2 * n; i++)
            if(!v[i])
                c[j++] = i;
        
        sort(all(b));
        reverse(all(b));
        
        sort(all(c));
        reverse(all(c));
    
        bool ans = true;

        for(int i = 0; i < n && ans; i++){
            if(b[i].first > c[i])
                ans = false;
            else
                a[2 * b[i].second + 1] = c[i];
        }

        if(!ans){
            cout << -1 << "\n";
        }
        else{
            for(int i = 1; i < 2 * n; i += 2){
                for(int j = i + 2; j < 2 * n; j += 2){
                    if(a[i] > a[j] && a[i - 1] < a[j] && a[j - 1] < a[i])
                        swap(a[i], a[j]);
                }
            }
            for(int i = 0; i < 2 * n; i++)
                cout << a[i] << " ";
            cout << "\n";
        }
    }
    
    return 0;   
}
