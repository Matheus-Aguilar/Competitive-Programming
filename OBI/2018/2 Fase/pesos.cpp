#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int>v(n + 1);
    v[0] = 0;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    bool possible = true;
    for(int i = 0; i < n; i++)
        if(v[i + 1] - v[i] > 8)
            possible = false;
    cout << (possible ? "S" : "N") << endl;
}