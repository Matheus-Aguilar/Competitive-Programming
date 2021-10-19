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

void solve(string &s, char a, char b){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == a){
            s[i] = b;
        }
        else if(s[i] == b){
            s[i] = a;
        }
    }
}

int main(){
    optimize;
    
    int t;
    cin >> t;

    while(t--){
        string s, ord;
        cin >> s;

        ord = s;
        sort(all(ord));
        ord.resize(unique(all(ord)) - ord.begin());

        int i = 0, j = 0;

        while(i < s.size() && j < ord.size()){
            if(ord[j] < s[i]){
                solve(s, ord[j], s[i]);
                break;
            }
            else if(ord[j] == s[i]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        cout << s << "\n";
    }

    return 0;   
}
