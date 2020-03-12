#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int d1, h1, m1, s1;
    int d2, h2, m2, s2;
    string aux;
    cin >> aux >> d1;
    cin >> h1 >> aux >> m1 >> aux >> s1;
    cin >> aux >> d2;
    cin >> h2 >> aux >> m2 >> aux >> s2;
    unsigned long long int res = 24 * 60 * 60 * (d2 - d1) + 60 * 60 * (h2 - h1) + 60 * (m2 - m1) + (s2 - s1);
    cout << res/(24 * 60 * 60) << " dia(s)\n";
    res %= 24 * 60 * 60;
    cout << res/(60 * 60) << " hora(s)\n";
    res %= 60 * 60;
    cout << res/60 << " minuto(s)\n";
    res %= 60;
    cout << res << " segundo(s)\n";
}