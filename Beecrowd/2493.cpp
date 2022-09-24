#include<bits/stdc++.h>

using namespace std;

struct Exp{
    int a, b, c;
};

int main(){
    int t;
    while(cin >> t){
        char equal;
        vector<Exp>ex(t);
        priority_queue<string, vector<string>, greater<string>>winners;
        for(int i = 0; i < t; i++)
            cin >> ex[i].a >> ex[i].b >> equal >> ex[i].c;
        for(int i = 0; i < t; i++){
            string name;
            int index;
            char op;
            cin >> name >> index >> op;
            --index;
            if(op == '+'){
                if(ex[index].a + ex[index].b != ex[index].c)
                    winners.push(name);
            }
            else if(op == '-'){
                if(ex[index].a - ex[index].b != ex[index].c)
                    winners.push(name);
            }
            else if(op == '*'){
                if(ex[index].a * ex[index].b != ex[index].c)
                    winners.push(name);
            }
            else{
                if(ex[index].a + ex[index].b == ex[index].c
                || ex[index].a - ex[index].b == ex[index].c
                || ex[index].a * ex[index].b == ex[index].c)
                    winners.push(name);        
            }
        }
        if(winners.size() == 0)
                cout << "You Shall All Pass!\n";
        else if(winners.size() == t)
            cout << "None Shall Pass!\n";
        else{
            while(!winners.empty()){
                cout << winners.top();
                winners.pop();
                if(!winners.empty()) cout << " ";
            }
            cout << "\n";
        }
    }
}