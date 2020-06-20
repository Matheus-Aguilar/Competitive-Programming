#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    set <int> s;
    int cont = 0;
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        if(s.count(aux)){
            cont++;
            s.erase(aux);
        }
        else{
            s.insert(aux);
        }
    }  
    cout << cont << endl;
}