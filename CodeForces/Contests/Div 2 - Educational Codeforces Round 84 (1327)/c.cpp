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

    int n, m, k, total = 0;
    cin >> n >> m;
    string s = "";

    total += n - 1;
    for(int i = 0; i < n - 1; i++)
        s += "U";
    total += m - 1;
    for(int i = 0; i < m - 1; i++)
        s += "L";
    if(m != 1 && n != 1){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i & 1)
                    s += "U";
                else
                    s += "D";
                total++;
            }
            s += "R";
            total++;
        }
    }
    else if(n == 1){
        total += m - 1;
        for(int i = 0; i < m - 1; i++)
            s += "R";
    }
    else{
        total += n - 1;
        for(int i = 0; i < n - 1; i++)
            s += "D";
    }

    cout << total << "\n" << s << "\n";

    return 0;   
}
