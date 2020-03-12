#include<bits/stdc++.h>

using namespace std;

int main(){
    double v[3];
    cin >> v[0] >> v[1] >> v[2];
    sort(v, v + 3);
    if(v[2] >= v[1] +v[0]) cout << "NAO FORMA TRIANGULO\n";
    else{
        if(v[2]* v[2] == v[1] * v[1] +v[0] * v[0]) cout << "TRIANGULO RETANGULO\n";
        else if(v[2]* v[2]> v[1] * v[1] +v[0] * v[0]) cout << "TRIANGULO OBTUSANGULO\n";
        else if(v[2]* v[2]< v[1] * v[1] +v[0] * v[0]) cout << "TRIANGULO ACUTANGULO\n";
        if(v[2]== v[1] && v[2]==v[0]) cout << "TRIANGULO EQUILATERO\n";
        else if(v[2]== v[1] || v[2]==v[0] || v[1] == v[0]) cout << "TRIANGULO ISOSCELES\n";
    }
}