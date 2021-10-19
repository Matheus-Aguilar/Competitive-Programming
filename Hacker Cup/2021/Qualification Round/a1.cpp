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

bool vowel(char c){
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main(){
    optimize;
    
    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){
        
        string s;
        cin >> s;

        int c = 0, v = 0;
        vector<int> f(26, 0);

        for(int i = 0; i < s.size(); i++){
            if(vowel(s[i])){
                v++;
            }
            else{
                c++;
            }

            f[s[i] - 'A']++;
        }

        int best = INF;

        for(int i = 0; i < 26; i++){
            char ch = 'A' + i;
            int cost = 0;

            if(vowel(ch)){
                cost = 2 * v + c - 2 * f[i];
            }
            else{
                cost = 2 * c + v - 2 * f[i];
            }

            best = min(best, cost);
        }

        cout << "Case #" << t << ": " << best << "\n";
    }

    return 0;   
}
