#include<bits/stdc++.h>

using namespace std;

int main(){
    double a, b, c, d, total = 0;
    cin >> a >> b >> c >> d;
    total = 2 * a + 3 * b + 4 * c + d;
    total /= 10;
    cout << "Media: " << fixed << setprecision(1) << total << endl;
    if(total >= 7){
        cout << "Aluno aprovado.\n";
        return 0;
    }
    else if(total < 5){
        cout << "Aluno reprovado.\n";
        return 0;
    }
    else{
        cout << "Aluno em exame.\n";
        double ex;
        cin >> ex;
        cout << "Nota do exame: " << fixed << setprecision(1) << ex << endl;
        total = (total + ex)/2;
        if(total >= 5){
            cout << "Aluno aprovado.\n";
        }
        else{
            cout << "Aluno reprovado.\n";
        }
        cout << "Media final: " << fixed << setprecision(1) << total << endl;
    }
}