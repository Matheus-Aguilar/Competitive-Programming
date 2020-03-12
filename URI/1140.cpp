#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        if(s == "*") break;
        char letter = tolower(s[0]);
        for(int i = 1; i < s.size(); i++){
            if(s[i] == ' ' && tolower(s[i + 1]) != letter){
                cout << "N\n";
                goto finish;
            }
        }
        cout << "Y\n";
        finish:
        int cPlusPlusShouldHaveDoubleBreak = true;
    }
}