#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;

    int n, m, t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<int> a(n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        int cont = 1;

        while(a[0] < m && cont < n){
            while(a[cont] && a[0] < m){
                a[cont]--;
                a[0]++;
            }
            cont++;
        }

        cout << a[0] << "\n";

    }
    return 0;   
}
