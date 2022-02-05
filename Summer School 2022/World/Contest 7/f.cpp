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
#define MAXN 20

using namespace std;

int n, m, c[MAXN];
string s[MAXN];

ll sum = 0;

void bt(int x){

    if(x == n){
        
        bool valid = true;

        for(int i = 0; i < m; i++){
            valid &= (c[i] == 0);
        }

        if(valid)
            sum++;

        return;
    }

    bool valid = true;

    for(int i = 0; i < m; i++){
        if(s[i][x] == '0'){
            c[i]--;
            valid &= (c[i] >= 0);
        }
    }

    if(valid)
        bt(x + 1);

    for(int i = 0; i < m; i++){
        if(s[i][x] == '0'){
            c[i]++;
        }
    }


    valid = true;

    for(int i = 0; i < m; i++){
        if(s[i][x] == '1'){
            c[i]--;
            valid &= (c[i] >= 0);
        }
    }

    if(valid)
        bt(x + 1);

    for(int i = 0; i < m; i++){
        if(s[i][x] == '1'){
            c[i]++;
        }
    }
}

int main(){
    optimize;

    cin >> n >> m;

    for(int i = 0; i < m; i++)
        cin >> s[i] >> c[i];
    
    bt(0);
    
    cout << sum << "\n";

    return 0;   
}
