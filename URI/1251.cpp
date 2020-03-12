#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    bool first = true;
    while(getline(cin, s)){
        cout << (!first ? "\n" : "");
        first &= false;
        vector<pair<int, int>>v(256);
        for(int i = 0; i < v.size(); i++) v[i] = make_pair(0, -i);
        for(int i = 0; i < s.size(); i++) v[s[i]].first++;
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++)
            if(v[i].first)
                cout << -v[i].second << " " << v[i].first << "\n";
    }
}