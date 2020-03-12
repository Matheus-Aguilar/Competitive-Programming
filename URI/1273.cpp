#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    bool first = true;
    while(cin >> n){
        if(!n) return 0;
        if(!first) cout << "\n";
        else first = false;
        int maxSize = 0;
        vector<string>s(n);
        for(int i = 0; i < n; i++){
            cin >> s[i];
            maxSize = max(maxSize, (int)s[i].size());
        }
        for(int i = 0; i < n; i++)
            cout << setw(maxSize) << s[i] << "\n";
    }
}