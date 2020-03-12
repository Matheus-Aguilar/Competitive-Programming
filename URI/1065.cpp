#include<bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c, d, e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    cout << !((a * a) & 1) + !((b * b) & 1) + !((c * c) & 1) + !((d * d) & 1) + !((e * e) & 1) << " valores pares\n";     
}