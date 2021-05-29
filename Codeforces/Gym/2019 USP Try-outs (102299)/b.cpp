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

string s;

char token;
stack<char> lex, word;

bool isDigit(char c){
    return '0' <= c && c <= '9';
}

bool getToken(){

    if(word.empty()) return false;

    do{
        token = word.top();
        word.pop();
    } while(token == ' ');

    return true;
}

//M -> '$' '|' P m | '|' M m | P m
//m -> '|' P m | ''
//P -> Tp
//p -> ':' T p | ''
//T -> '{' M '}' | I
//I -> '0' | '1' | '2' | ... | '9' | '0'I | '1'I | ... | '9'I

bool parse(){
    
    lex.push('M');
    getToken();

    while(!lex.empty()){

        //cout << lex.top() << " " << token << " " << lex.size() << endl;

        if(lex.top() == token){
            lex.pop();
            getToken();
        }
        else if(lex.top() == 'M'){
            if(token == '$'){
                lex.pop();
                lex.push('m');
                lex.push('P');
                lex.push('|');
                lex.push('$');
            }
            else if(token == '|'){
                lex.pop();
                lex.push('m');
                lex.push('M');
                lex.push('|');
            }
            else if(token == '{' || isDigit(token)){
                lex.pop();
                lex.push('m');
                lex.push('P');
            }
            else{
                return false;
            }
        }
        else if(lex.top() == 'm'){
            
            lex.pop();
            
            if(token == '|'){
                lex.push('m');
                lex.push('P');
                lex.push('|');
            }
        }
        else if(lex.top() == 'P'){
            lex.pop();
            lex.push('p');
            lex.push('T');
        }
        else if(lex.top() == 'p'){
            
            lex.pop();
            
            if(token == ':'){
                lex.push('p');
                lex.push('T');
                lex.push(':');
            }
        }
        else if(lex.top() == 'T'){
            if(token == '{'){
                lex.pop();
                lex.push('}');
                lex.push('M');
                lex.push('{');
            }
            else if(isDigit(token)){
                lex.pop();
                lex.push('I');
            }
            else{
                return false;
            }
        }
        else if(lex.top() == 'I'){
            if(isDigit(token)){
                
                lex.pop();
                
                while(isDigit(word.top())){
                    word.pop();
                }

                getToken();
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }

    return token == 'x';
}

int main(){
    optimize;
    
    string s;
    getline(cin, s);

    s += "x";

    for(int i = s.size() - 1; i >= 0; i--)
        word.push(s[i]);

    cout << (parse() ? "YES" : "NO") << "\n";

    return 0;   
}
