#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);

        int small = INF;
        int big = 0;

        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n - 1; i++){
            if(a[i] == -1 && a[i + 1] != -1){
                small = min(small, a[i + 1]);
                big = max(big, a[i + 1]);
            }
            else if(a[i + 1] == -1 && a[i] != -1){
                small = min(small, a[i]);
                big = max(big, a[i]);
            }
        }

        int k = small + (big - small)/2;
        int m = 0;

        replace(a.begin(), a.end(), -1, k);

        for(int i = 0; i < n - 1; i++)
            m = max(m, abs(a[i] - a[i + 1]));
        
        cout << m << " " << k << "\n";
    }
    return 0;   
}
