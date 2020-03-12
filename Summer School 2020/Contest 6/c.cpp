#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int m(string &s){
    if(s == "red") return 1;
    if(s == "yellow") return 2;
    if(s == "green") return 3;
    if(s == "brown") return 4;
    if(s == "blue") return 5;
    if(s == "pink") return 6;
    if(s == "black") return 7;
}

int main(){
    optimize;

    int n, maior = 0, vermelhos = 0, soma = 0;
    cin >> n;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;

        maior = max(maior, m(s));
        soma += m(s);
        if(s == "red") vermelhos++;
    }

    if(vermelhos == n)
        cout << 1 << "\n";
    else
        cout << maior * vermelhos + soma << "\n";
}