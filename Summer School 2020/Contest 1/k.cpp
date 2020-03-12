#include<bits/stdc++.h>
#define MAX 18446744073709551614ull

using namespace std;

int main(){
    
    string s;
    cin >> s;

    vector<int> root;

    for(int i = 1; i < s.size(); i++)
        if(s[i] != s[i - 1])
            root.push_back(2 * i + 1);

    vector<long long int> coef(root.size() + 1, 0);
    vector<long long int> aux(root.size() + 1, 0);
    
    coef[0] = aux[0] = 1;

    for(int i = 0; i < root.size(); i++){
        for(int j = 0; j < i + 2; j++){
            if(!j)
                aux[j] = -coef[j] * root[i];
            else
                aux[j] = -coef[j] * root[i] + coef[j - 1];
        }
        coef = aux;
    }

    long long int test = coef[0];
    int inversor = ((test > 0 && s[0] == 'H') || (test < 0 && s[0] == 'A') ? 1 : -1);

    cout << root.size() << "\n";
    for(int i = coef.size() - 1; i > 0; i--)
        cout << coef[i] * inversor << " ";
    cout << coef[0] * inversor << "\n";

    return 0;
}