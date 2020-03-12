#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

bool isOperator(char c){
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '\%';
}

int main(){
    string s = "(", line;
    getline(cin, line);

    s += line + ')';


    //Limpa os espaços da string
    s.erase(remove_if(s.begin(), s.end(), [](char c){ return c == ' ';}), s.end());

    stack<char> st;
    bool improper = false;

    if(s.size() == 2){
        cout << "error" << "\n";
        return 0;
    }

    if((s.size() == 3 && isalpha(s[1]))){
        cout << "proper" << "\n";
        return 0;
    }

    //Checa balanceamento de parenteses
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(')
            st.push('(');
        else if(s[i] == ')'){
            if(st.empty() || st.top() != '('){
                cout << "error" << "\n";
                return 0;
            }
            st.pop();
        }
    }

    //Sobrou parenteses sem fechar
    if(!st.empty()){
        cout << "error" << "\n";
        return 0;
    }

    for(int i = 0; i < s.size(); i++){
        if(s[i] != ')'){
            st.push(s[i]);
        }
        else{

            string w = "";
            while(st.top() != '('){
                w += st.top();
                st.pop();
            }

            reverse(w.begin(), w.end());
            if(w.size() == 0 || isOperator(w[0]) || isOperator(w.back())){
                cout << "error" << "\n";
                return 0;
            }

            for(int i = 1; i < w.size(); i++){
                if((isalpha(w[i]) && isalpha(w[i - 1])) || (isOperator(w[i]) && isOperator(w[i - 1]))){
                    cout << "error" << "\n";
                    return 0;
                }
            }

            if(w.size() != 3){
                improper = true;
            }
            
            st.pop();
            st.push('x');
        }
    }

    cout << (improper ? "improper" : "proper") << "\n";
    return 0;
}