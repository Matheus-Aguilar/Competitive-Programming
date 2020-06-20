#include<bits/stdc++.h>

using namespace std;

void copia(const string &s1, string &s2, char v1, char v2){
    s2 = "";
    for(int i = 0; i < s1.size(); i++)
        if(s1[i] == v1 || s1[i] == v2)
            s2 = s2 + s1[i];
}

bool temrepetido(const string &s){
    for(int i  = 0; i < s.size() - 1; i++)
        if(s[i] == s[i+1])
            return true;
    return false;
}

int main(){
    int n;
    cin >> n;
    string s, aux;
    getline(cin, s);
    getline(cin, s);
    int maior = 0;
    for(char i = 'a'; i <= 'z'; i++){
        for (char j = 'a'; j <= 'z'; j++){
            copia(s, aux, i, j);
            int tam = aux.size();
            if (!temrepetido(aux) && tam > 1)
                maior = max(maior, tam);
        }
    }
    cout << maior << endl;
}