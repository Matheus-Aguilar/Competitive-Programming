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

    string s, m = "";
    cin >> s;

    for(int i = 0; i < s.size(); i++){
        
        if(s[i] == 'R'){
            m += 'S';
        }
        else if(s[i] == 'B'){
            m += 'K';
        }
        else if(s[i] == 'L'){
            m += 'H';
        }

        int n = m.size();

        if(n >= 3){
            if(m[n - 3] != m[n - 2] && m[n - 2] != m[n - 1] && m[n - 3] != m[n - 1] && m[n - 3] != 'C' && m[n - 2] != 'C' && m[n - 1] != 'C'){
                m.pop_back();
                m.pop_back();
                m.pop_back();
                m += 'C';
            }
        }
    }

    cout << m << "\n";
    
    return 0;   
}
