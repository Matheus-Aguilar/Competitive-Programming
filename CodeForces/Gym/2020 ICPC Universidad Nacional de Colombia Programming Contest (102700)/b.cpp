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

string solve(string &s){
    
    string best = "";
    best += s[0];

    for(int i = 1; i < s.size(); i++){
        if(s[i] > best[0]){
            best = "";
            best += s[i];
        }
        else if(s[i] < best[0]){
            best += s[i];
        }
        else{

            int j;

            string now = "";
            now += s[i++];

            for(j = 0;  j < best.size() - 1 && i < s.size() && best[j] == now[j]; j++, i++){
                now += s[i];
            }

            if(now.back() > best[0]){
                best = "";
                best += now.back();
            }
            else if(now > best){
                best = now;
            }
            else{
                best += now;
            }

            i--;
        }
    }
    return best;
}

int main(){
    optimize;

    string a, b, c, d, ans = "";
    cin >> a >> b;
    
    c = solve(a);
    d = solve(b);

    ans += c[0];

    for(int i = 1; c[i] >= d[0] && i < c.size(); i++)
        ans += c[i];

    ans += d;

    cout << ans << "\n";

    return 0;   
}
