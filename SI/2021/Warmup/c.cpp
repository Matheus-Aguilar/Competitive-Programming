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

int main(){
    optimize;

    int n;
    vector<vector<int>> c(10, vector<int>(30, 0));

    cin >> n;

    for(int i = 0; i < n; i++){
        int m;
        cin >> m;

        for(int j = 0; j < m; j++){
            int d, ii, ff;
            char aux;

            cin >> d >> aux >> ii >> aux >> ff;

            for(int k = ii; k < ff; k++){
                c[d][k]++;
            }
        }
    }

    bool conf = false;

    for(int i = 0; i < c.size(); i++){
        for(int j = 0; j < c[i].size(); j++){
            if(c[i][j] > 1){
                conf = true;
            }
        }
    }

    cout << (conf ? "SIM" : "NAO") << "\n";
    
    return 0;   
}
