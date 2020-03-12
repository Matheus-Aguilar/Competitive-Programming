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
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        for(int i = 0; i < d; i++){
            for(int j = 1; j < n; j++){
                if(a[j]){
                    a[j - 1]++;
                    a[j]--;
                    break;
                }
            }
        }

        cout << a[0] << "\n";
    }
    
    return 0;   
}
