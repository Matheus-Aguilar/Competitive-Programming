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

    int q;
    cin >> q;
    while(q--){
        string s, t;
        int n, m, cont, pos = 25;
        bool solved = false;

        cin >> s >> m;
        
        vector<int> a(m);
        vector<int> b(m);
        vector<int> c(26, 0);
        t.resize(m);
        
        for(int i = 0; i < m; i++)
            cin >> b[i];
        for(int i = 0; i < s.size(); i++)
            c[(int)(s[i] - 'a')]++;
        while(!solved){
            cont = 0;
            solved = true;

            for(int i = 0; i < m; i++){
                if(b[i] == 0){
                    solved = false;
                    a[cont++] = i;
                }
            }

            for(int i = 0; i < cont; i++){
                for(int j = 0; j < m; j++){
                    if(b[j] > 0){
                        b[j] -= abs(a[i] - j);
                    }
                }
            }

            for(int i = pos; i >= 0; i--){
                if(cont <= c[i]){
                    for(int j = 0; j < cont; j++){
                        b[a[j]] = -1;
                        t[a[j]] = (char)(i + 'a');
                    }
                    c[i] -= cont;
                    pos = i - 1;
                    break;
                }
            }
        }
        cout << t << "\n";
    }
        
    return 0;   
}
