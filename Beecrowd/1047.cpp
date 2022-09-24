#include<bits/stdc++.h>

using namespace std;

int main(){
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    int t1 = h1 * 60 + m1;
    int t2 = h2 * 60 + m2;
    int res;

    if(t2 <= t1)
        res = t2 - t1 + 24 * 60;
    else
        res = t2 - t1;
    cout << "O JOGO DUROU " << res/60 << " HORA(S) E " << res % 60 << " MINUTO(S)\n"; 
}