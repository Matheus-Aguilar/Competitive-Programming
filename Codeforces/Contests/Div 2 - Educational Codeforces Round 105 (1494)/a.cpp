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

bool check(string &s){
    int sum = 0;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            sum++;
        }
        else{
            sum--;
        }
        
        if(sum < 0) return false;
    }

    return sum == 0;
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){

        bool ok = false;

        string s, t;
        cin >> s;

        for(int i = 0; i < 2 && !ok; i++){
            for(int j = 0; j < 2 && !ok; j++){
                for(int k = 0; k < 2 && !ok; k++){
                    t = "";

                    for(int l = 0; l < s.size(); l++){
                        if(s[l] == 'A')
                            t += (i ? '(' : ')');
                        if(s[l] == 'B')
                            t += (j ? '(' : ')');
                        if(s[l] == 'C')
                            t += (k ? '(' : ')');
                    }

                    if(check(t)){
                        ok = true;
                    }  
                }
            }    
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
    
    return 0;   
}
