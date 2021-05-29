#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

string m[5][7] = {
    {"$|Pm", "|Mm", "Pm", "*", "*", "Pm", "*"},
    {"*", "|Pm", "*", "", "*", "*", ""},
    {"*", "*", "Tp", "*", "*", "Tp", "*"},
    {"*", "", "*", "", ":Tp", "*", ""},
    {"*", "*", "{M}", "*", "*", "I", "*"}
};

int nonTerminal(char c){
    switch(c){
        case 'M':
            return 0;
        case 'm':
            return 1;
        case 'P':
            return 2;
        case 'p':
            return 3;
        case 'T':
            return 4;
        default:
            return -1;
    }
}

int terminal(char c){
    switch(c){
        case '$':
            return 0;
        case '|':
            return 1;
        case '{':
            return 2;
        case '}':
            return 3;
        case ':':
            return 4;
        case 'I':
            return 5;
        case 'x':
            return 6;
        default:
            return -1;
    }
}

pair<char, int> getToken(string &s, int i){
    
    char c = ' ';

    while(i < s.size() && c == ' '){
        c = s[i];
        i++;
    }

    if('0' <= c && c <= '9'){
        while(i < s.size() && '0' <= s[i] && s[i] <= '9'){
            i++;
        }
        c = 'I';
    }

    return make_pair(c, i);
}

bool parse(string &s){
    
    stack<char> lex;

    lex.push('x');
    lex.push('M');

    pair<char, int> token = getToken(s, 0);

    while(!lex.empty()){
        
        int line = nonTerminal(lex.top()), col = terminal(token.first);

        //cout << lex.top() << " " << token.first << "\n";
        
        if(line != -1){

            if(col == -1 || m[line][col] == "*")
                return false;

            lex.pop();

            for(int i = m[line][col].size() - 1; i >= 0; i--)
                lex.push(m[line][col][i]);
             
        }
        else{
            if(lex.top() == token.first){
                lex.pop();
                token = getToken(s, token.second);
            }
            else{
                return false;
            }
        }
    }

    return true;
}

int main(){
    optimize;
    
    string s;
    getline(cin, s);

    s += " x";

    cout << (parse(s) ? "YES" : "NO") << "\n";

    return 0;   
}
