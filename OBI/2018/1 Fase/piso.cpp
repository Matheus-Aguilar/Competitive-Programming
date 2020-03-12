#include<bits/stdc++.h>

using namespace std;

int main(){
    int l, a;
    cin >> l >> a;
    int l1, l2;
    l2 = 2 * (l + a - 2);
    l1 = 2 * l * a - l - a + 1;
    cout << l1 << "\n" << l2 << endl;
}