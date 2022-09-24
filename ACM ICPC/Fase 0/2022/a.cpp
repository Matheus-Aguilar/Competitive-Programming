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
    cin >> n;
    cin.ignore();

    while(n--){
        string s, line;

        getline(cin, s);
        getline(cin, line);

        stringstream ss;
        ss << line;

        double vals[5], ans;
        int cont = 0;

        while(ss >> vals[cont]){
            cont++;
        }

        if(cont == 1)
            ans = vals[0] / 2.0;
        else if(cont == 2)
            ans = (vals[0] + vals[1]) / 2.0;
        else if(cont == 3)
            ans = (vals[0] + vals[1] + vals[2]) / 3.0;
        else
            ans = (vals[0] + vals[1] + vals[2] + vals[3] - *min_element(vals, vals + 4)) / 3.0;
        
        cout << s << ": " << fixed << setprecision(1) << ans << "\n";
    }
    
    return 0;   
}
