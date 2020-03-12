#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;
    
    int n, v0, vi;
    cin >> n >> v0;

    while(--n){
        cin >> vi;
        if(vi > v0){
            cout << "N" << "\n";
            return 0;
        }
    }

    cout << "S" << "\n";
    
    return 0;   
}
