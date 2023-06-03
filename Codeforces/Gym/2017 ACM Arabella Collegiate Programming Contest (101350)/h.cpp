#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

using namespace std;

const char c[] = {'A','H','I','M','O','T','U','V','W','X','Y'};

int main(){

    optimize;

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        bool ok = true;

        for(int i = 0; i < s.size(); i++){
            ok = false;
            for(int j = 0; j < 11; j++){
                if(c[j] == s[i]){
                    ok = true;
                    break;
                }
            }
            if(!ok){
                break;
            }
        }

        if(ok){
            for(int i = 0, j = s.size() - 1; i < j; i++, j--){
                if(s[i] != s[j]){
                    ok = false;
                    break;
                }
            }
        }

        cout << (ok ? "yes" : "no") << "\n";
    }

    return 0;
}