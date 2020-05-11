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

void floodFill(int i, int j, int r, int c, vector<string> &m){
    if(i < 0 || j < 0 || i >= r || j >= c || m[i][j] == '.')
        return;
    m[i][j] = '.';
    floodFill(i - 1, j, r, c, m);
    floodFill(i + 1, j, r, c, m);
    floodFill(i, j - 1, r, c, m);
    floodFill(i, j + 1, r, c, m);
}

int main(){
    optimize;

    int r, c;
    cin >> r >> c;
    vector<string> m(r);
    for(int i = 0; i < r; i++)
        cin >> m[i];
    bool ans = true;
    bool whiteCol = false, whiteRow = false;
    
    for(int i = 0; i < r && ans; i++){
        bool onBlack = false;
        int contBlack = 0;
        for(int j = 0; j < c && ans; j++){
            if(m[i][j] == '#'){
                if(!onBlack){
                    contBlack++;
                    onBlack = true;
                }
            }
            else{
                onBlack = false;
            }
        }
        if(contBlack == 0)
            whiteRow = true;
        else if(contBlack > 1)
            ans = false;
    }

    for(int i = 0; i < c && ans; i++){
        bool onBlack = false;
        int contBlack = 0;
        for(int j = 0; j < r && ans; j++){
            if(m[j][i] == '#'){
                if(!onBlack){
                    contBlack++;
                    onBlack = true;
                }
            }
            else{
                onBlack = false;
            }
        }
        if(contBlack == 0)
            whiteCol = true;
        else if(contBlack > 1)
            ans = false;
    }

    ans &= !(whiteRow ^ whiteCol);

    if(!ans){
        cout << -1 << "\n";
    }
    else{

        int numComp = 0;

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(m[i][j] == '#'){
                    numComp++;
                    floodFill(i, j, r, c, m);
                }
            }
        }

        cout << numComp << "\n";
    }
    
    return 0;   
}
