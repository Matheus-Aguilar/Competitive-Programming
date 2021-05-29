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
#define fi first
#define se second

using namespace std;

void fix(string &s){
    string fixed = "";

    for(int i = 0; i < s.size(); i++){
        
        if(i == 0 && s[i] == 'x')
            fixed += '1';

        fixed += s[i];

        if(s[i] == '+' || s[i] == '-'){
            if(s[i + 1] == 'x'){
                fixed += '1';
            }
        }

        if(s[i] == 'x'){
            if(i == s.size() - 1 || s[i + 1] == '+' || s[i + 1] == '-')
                fixed += '1';
        }
    }

    s = fixed;
}

int main(){
    optimize;

    string s;
    stringstream ss;

    vector<pii> poly;

    int coef, power;
    char x;

    cin >> s;

    fix(s);

    ss << s;

    while(ss >> coef >> x >> power){
        poly.emplace_back(coef, power);
    }

    if(poly.size() == 0){
        cout << "0" << "\n";
    }
    else{
        for(int i = 0; i < poly.size(); i++){
            poly[i].fi *= poly[i].se;
            poly[i].se--;
        }

        for(int i = 0; i < poly.size(); i++){
            
            if(poly[i].fi < 0)
                cout << "-";
            else if(i > 0)
                cout << "+";
            
            if(poly[i].se == 0){
                cout << abs(poly[i].fi);
            }
            else if(poly[i].se == 1){
                
                if(abs(poly[i].fi) > 1)
                    cout << abs(poly[i].fi);
                
                cout << "x";
            }
            else{
                if(abs(poly[i].fi) > 1)
                    cout << abs(poly[i].fi);
                
                cout << "x";

                cout << poly[i].se;
            }
        }

        cout << "\n";
    }
    
    return 0;   
}
