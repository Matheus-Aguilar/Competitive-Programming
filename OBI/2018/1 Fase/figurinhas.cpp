#include<bits/stdc++.h>

using namespace std;

int main(){
    int n, c, m;
    cin >> n >> c >> m;
    int res = c;
    vector<bool>v(n, false);
    while(c--){
        int f;
        cin >> f;
        v[f - 1] = true;
    }
    while(m--){
        int f;
        cin >> f;
        if(v[f - 1]){
            --res;
            v[f - 1] = false;
        }
    }
    cout << res << endl;
}