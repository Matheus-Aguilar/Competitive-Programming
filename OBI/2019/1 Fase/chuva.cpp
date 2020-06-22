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

int n, m;
char s[510][510];

void bt(int i, int j){
    if(i < 0 || j < 0 || i >= n || j >= m || s[i][j] != '.')
        return;
    s[i][j] = 'o';
    if(i < n - 1 && s[i + 1][j] == '#'){
        bt(i, j - 1);
        bt(i, j + 1);
    }
    else{
        bt(i + 1, j);
    }
}

int main(){
    //optimize;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> s[i][j];
        }
    }

    bool solved = false;

    for(int i = 0; i < n && !solved; i++){
        for(int j = 0; j < m && !solved; j++){
            if(s[i][j] == 'o'){
                s[i][j] = '.';
                bt(i, j);
                solved = true;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << s[i][j];
        }
        cout << endl;
    }
    
    return 0;   
}
