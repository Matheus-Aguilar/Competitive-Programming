#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, k, x, best = 1;
    cin >> n >> k;
    
    vector<int> v(n);

    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    int now = 1;

    for(int i = 1; i < n; i++){
        if(abs(v[i - 1] - v[i]) > k)
            now = 1;
        else
            now++;
        best = max(best, now); 
    }

    cout << best << "\n";

    return 0;
}