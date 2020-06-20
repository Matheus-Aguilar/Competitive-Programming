#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    set <int> con;
    int cont = 1;
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] == s[i+1]){
            con.insert(cont * (int)(s[i] - 'a' + 1));
            cont++;
        }
        else{
            con.insert(cont * (int)(s[i] - 'a' + 1));
            cont = 1;
        }
    }
    con.insert(cont * (int)(s[s.size()-1] - 'a' + 1));

    int cons;
    cin >> cons;

    while(cons--){
        int aux;
        cin >> aux;
        if(con.count(aux))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}