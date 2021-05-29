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


void print(int r1, int c1, int r2, int c2, char a){
    cout << r1 << ":" << c1 << ": ";
    cout << "warning: shadowed declaration of " << a << ", the shadowed position is ";
    cout << r2 << ":" << c2 << "\n";
}

int main(){
    optimize;
    
    int n, r, c;
    cin >> n;

    cin.ignore();

    vector<vector<pii>> var(26);
    vector<vector<char>> esc(1, vector<char>());

    string line;

    for(r = 1; r <= n; r++){
        getline(cin, line);
        for(int i = 1; i <= line.size(); i++){
            char ch = line[i - 1];

            if(ch == '{'){
                esc.emplace_back();
            }
            else if(ch == '}'){

                for(int j = 0; j < esc.back().size(); j++)
                    var[esc.back()[j] - 'a'].pop_back();

                esc.pop_back();
            }
            else if(ch != ' '){
                
                if(var[ch - 'a'].size() > 0)
                    print(r, i, var[ch - 'a'].back().fi, var[ch - 'a'].back().se, ch);
                
                var[ch - 'a'].emplace_back(r, i);
                esc.back().push_back(ch);
            }
        }
    }

    return 0;   
}
