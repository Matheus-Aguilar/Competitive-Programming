#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int main(){
    optimize;

    int n, t;
    cin >> n;

    vector<int> h(n);

    for(int i = 0; i < n; i++)
        cin >> h[i];

    cin >> t;
    
    int best = t % h[0], index = 0;

    for(int i = 1; i < n; i++){
        if(best > t % h[i]){
            best = t % h[i];
            index = i;
        }
    }

    cout << h[index] << "\n";
}