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

ll calc(string &s){
    
    ll sum = 0LL, pot = 1LL;
    
    for(int i = s.size() - 1; i >= 0; i--){
        if(s[i] == 'x')
            continue;
        if(s[i] == '1')
            sum += pot;
        pot <<= 1;
    }

    return sum;
}

int main(){
    optimize;

    int cont = 0;
    ll k;
    string s;

    cin >> k >> s;

    while(calc(s) > k){
        
        bool hasOne = false;

        for(int i = 1; i < s.size(); i++){
            if(s[i] == '1'){
                s[i] = 'x';
                hasOne = true;
                break;
            }
        }

        for(int i = 1; i < s.size() && !hasOne; i++){
            if(s[i] == '0'){
                s[i] = 'x';
                break;
            }
        }
        
        cont++;
    }

    cout << cont << "\n";

    return 0;   
}