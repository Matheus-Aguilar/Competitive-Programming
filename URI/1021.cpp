#include<bits/stdc++.h>

using namespace std;

int main(){
    int notes, cents, total;
    char point;
    cin >> notes >> point >> cents;

    total = notes * 100 + cents;

    int quant[12];
    memset(quant, 0, sizeof(quant));

    quant[0] = total / 10000;
    total %= 10000;
    quant[1] = total / 5000;
    total %= 5000;
    quant[2] = total / 2000;
    total %= 2000;
    quant[3] = total / 1000;
    total %= 1000;
    quant[4] = total / 500;
    total %= 500;
    quant[5] = total / 200;
    total %= 200;
    quant[6] = total / 100;
    total %= 100;
    quant[7] = total / 50;
    total %= 50;
    quant[8] = total / 25;
    total %= 25;
    quant[9] = total / 10;
    total %= 10;
    quant[10] = total / 5;
    total %= 5;
    quant[11] = total / 1;

    cout << "NOTAS:\n";
    cout << quant[0] << " nota(s) de R$ 100.00\n";
    cout << quant[1] << " nota(s) de R$ 50.00\n";
    cout << quant[2] << " nota(s) de R$ 20.00\n";
    cout << quant[3] << " nota(s) de R$ 10.00\n";
    cout << quant[4] << " nota(s) de R$ 5.00\n";
    cout << quant[5] << " nota(s) de R$ 2.00\n";
    cout << "MOEDAS:\n";
    cout << quant[6] << " moeda(s) de R$ 1.00\n";
    cout << quant[7] << " moeda(s) de R$ 0.50\n";
    cout << quant[8] << " moeda(s) de R$ 0.25\n";
    cout << quant[9] << " moeda(s) de R$ 0.10\n";
    cout << quant[10] << " moeda(s) de R$ 0.05\n";
    cout << quant[11] << " moeda(s) de R$ 0.01\n";
}