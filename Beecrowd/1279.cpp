#include<bits/stdc++.h>

using namespace std;

int ctoi(char c){
    return (int)(c - '0');
}

bool div3(string &s){
    int res = 0;
    for(int i = 0; i < s.size(); i++)
        res += ctoi(s[i]);
    return !(res % 3);
}

bool div4(string &s){
    int res = ctoi(s[s.size() - 1]) + 10 * (s.size() > 1 ? ctoi(s[s.size() - 2]) : 0);
    return !(res % 4);
}

bool div5(string &s){
    return !(ctoi(s[s.size() - 1]) % 5);
}

bool div11(string &s){
    int res = 0;
    for(int i = 0; i < s.size(); i++)
        res += ctoi(s[i]) * (i & 1 ? 1 : -1);
    res = abs(res);
    return !(res % 11);
}

bool div15(string &s){
    return div3(s) && div5(s);
}

bool div55(string &s){
    return div5(s) && div11(s);
}

bool div100(string &s){
    if(s == "0") return true;
    if(s.size() == 1) return false;
    return !(ctoi(s[s.size() - 1]) || ctoi(s[s.size() - 2]));
}

bool div400(string &s){
    if(s == "0") return true;
    if(s.size() < 3 || !div100(s)) return false;
    int res = ctoi(s[s.size() - 3]) + 10 * (s.size() > 3 ? ctoi(s[s.size() - 4]) : 0);
    return !(res % 4);
}

int main(){
    bool first = true;
    string s;
    while(cin >> s){
        if(first) first = false;
        else cout << "\n";

        bool ordinary = true;
        if((!div100(s) && div4(s)) || div400(s)){
            cout << "This is leap year.\n";
            ordinary = false;
        }
        if(div15(s)){
            cout << "This is huluculu festival year.\n";
            ordinary = false;
        }
        if(div55(s) && ((!div100(s) && div4(s)) || div400(s))){
            cout << "This is bulukulu festival year.\n";
            ordinary = false;
        }
        if(ordinary){
            cout << "This is an ordinary year.\n";
        }
    }
}