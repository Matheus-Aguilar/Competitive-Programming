#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 1000000007
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;


vector<string> m(9);
void change(int i, int j){
    m[i][j] = (m[i][j] == '1' ? '2' : '1');
}

int main(){
    optimize;
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 9; i++)
            cin >> m[i];
        change(0, 0);
        change(1, 3);
        change(2, 6);
        change(3, 1);
        change(4, 4);
        change(5, 7);
        change(6, 2);
        change(7, 5);
        change(8, 8);
        for(int i = 0; i < 9; i++)
            cout << m[i] << "\n";
    }
    
    return 0;   
}
