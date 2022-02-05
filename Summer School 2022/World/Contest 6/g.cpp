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

int n, g[20][20], v[20][20];
string s;
bool first;

void bt(int i, int j){

    if(i < 0 || j < 0 || i >= n || j >= n || g[i][j] == 0 || v[i][j])
        return;
    
    if(i == n - 1 && j == n - 1){
        if(!first) 
            cout << " ";
        else
            first = false;
        cout << s;
    }

    v[i][j] = true;

    s += "D";
    bt(i + 1, j);
    s.pop_back();

    s += "L";
    bt(i, j - 1);
    s.pop_back();

    s += "R";
    bt(i, j + 1);
    s.pop_back();

    s += "U";
    bt(i - 1, j);
    s.pop_back();

    v[i][j] = false;
}

int main(){
    optimize;
    
    int t;
    cin >> t;

    while(t--){
        
        cin >> n;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> g[i][j];
            }
        }

        s = "";
        first = true;

        bt(0, 0);
        cout << "\n";
    }

    return 0;   
}