#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>>m(n);
    for(int i = 0; i < n; i++)
        cin >> m[i].first >> m[i].second;
    sort(m.begin(), m.end());
    for(int i = 1; i < n; i++){
        if(m[i - 1].second < m[i].second){
            cout << "N" << "\n";
            return 0;
        }
    }
    cout << "S" << "\n";
}