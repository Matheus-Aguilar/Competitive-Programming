#include<bits/stdc++.h>

using namespace std;

int precedence(char c){
    switch(c){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string infix, posfix = "";
        cin >> infix;

        stack<char> operations;

        for(int i = 0; i < infix.size(); i++){
            char c = infix[i];

            if(isalnum(c))
                posfix += c;
            else if(c == '(')
                operations.push(c);
            else if(c == ')'){
                while(!operations.empty() && operations.top() != '('){
                    posfix += operations.top();
                    operations.pop();
                }
                operations.pop();
            }
            else if(c == '^')
                operations.push(c);
            else{
                while(!operations.empty() && precedence(c) <= precedence(operations.top())){
                    posfix += operations.top();
                    operations.pop();
                }
                operations.push(c);
            }
        }

        while(!operations.empty()){
            posfix += operations.top();
            operations.pop();
        }
        cout << posfix << "\n";
    }    
}