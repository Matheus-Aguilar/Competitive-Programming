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
    
    string s, text = "", words[4] = {"capivara", "capivaro", "capivarista", "capivaristo"};

    while(getline(cin, s)){
        
        for(int i = 0; i < s.size(); i++)
            if(isalpha(s[i]))
                s[i] = tolower(s[i]);
        
        text += s;
        text += ' ';
    }

    for(int i = 0; i < 4; i++){
        if(text.find(words[i]) != string::npos){
            cout << "YES" << "\n";
            return 0;
        }
    }

    cout << "NO" << "\n";

    return 0;   
}
