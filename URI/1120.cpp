#include<bits/stdc++.h>

using namespace std;

void removeDigit(char d, string &s){
    for(int i = 0; i < s.size(); i++)
        if(s[i] == d)
            s[i] = '-';
}

int main(){
    char n;
    string s;
    while(cin >> n){
        if(n == '0') return 0;
        cin >> s;
        removeDigit(n, s);
        int i = 0;
        while((s[i] == '0' || s[i] == '-') && i != s.size()) i++;
        if(i == s.size()){
            cout << 0;
        }
        else{
            while(i < s.size()){
                if(s[i] != '-') cout << s[i];
                i++;
            }
        }
        cout << "\n";
    }
}