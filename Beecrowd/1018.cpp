#include<bits/stdc++.h>

using namespace std;

int main(){
    int total, valor;
    cin >> valor;
    total = valor;

    int quant[7];
    memset(quant, 0, sizeof(quant));

    quant[0] = total / 100;
    total %= 100;
    quant[1] = total / 50;
    total %= 50;
    quant[2] = total / 20;
    total %= 20;
    quant[3] = total / 10;
    total %= 10;
    quant[4] = total / 5;
    total %= 5;
    quant[5] = total / 2;
    total %= 2;
    quant[6] = total / 1;
    total %= 1;

    cout << valor << "\n";
    cout << quant[0] << " nota(s) de R$ 100,00\n";
    cout << quant[1] << " nota(s) de R$ 50,00\n";
    cout << quant[2] << " nota(s) de R$ 20,00\n";
    cout << quant[3] << " nota(s) de R$ 10,00\n";
    cout << quant[4] << " nota(s) de R$ 5,00\n";
    cout << quant[5] << " nota(s) de R$ 2,00\n";
    cout << quant[6] << " nota(s) de R$ 1,00\n";
}