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
        int n, x, maior = 0; bool temIgual = false;
        cin >> n >> x;
        
        vector<int> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
            maior = max(maior, a[i]);
            if(a[i] == x) temIgual = true;
        }
        
        if(temIgual){
            cout << 1 << "\n";
        }
        else if(maior > x){
            cout << 2 << "\n";
        }
        else if(x % maior == 0){
            cout << x/maior << "\n";
        }
        else{
            cout << x/maior + 1 << "\n";
        }
    }

    return 0;   
}
