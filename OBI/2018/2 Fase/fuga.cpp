#include<bits/stdc++.h>
using namespace std;

int maximum = 0;

void bt(int n, int m, int x, int y, int a, int b, vector<bool>&v, int cont){
    if(x < 0 || y < 0 || x >= n || y >= m || v[x * m + y] || (x % 2 && y % 2)) return;
    if(x == a && y == b){
        maximum = max(cont, maximum);
        return;
    }
    v[x * m + y] = true;
    bt(n, m, x - 2, y, a, b, v, cont + 2);
    bt(n, m, x + 2, y, a, b, v, cont + 2);
    bt(n, m, x, y - 2, a, b, v, cont + 2);
    bt(n, m, x, y + 2, a, b, v, cont + 2);
    v[x * m + y] = false;
}

int main(){
    int n, m;
    int x, y;
    int a, b;
    cin >> n >> m >> x >> y >> a >> b;
    vector<bool>v(n * m, false);
    bt(n, m, x - 1, y - 1, a - 1, b - 1, v, 1);
    cout << maximum << endl;
}