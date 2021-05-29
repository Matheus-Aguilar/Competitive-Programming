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

bool palind(string &a, int ini, int fim){
    int i = ini, j = fim;
    while(i < j){
        if(a[i++] != a[j--]) return false;
    }
    return true;
}

void copiar(string &a, string &b, int ini, int fim){
    b = "";
    for(int i = ini; i <= fim; i++)
        b += a[i];
}

int main(){
    optimize;
    
    int t;
    cin >> t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin, s);
        string s2 = ' ' + s + ' ';
        int i = 0, j = s.size() + 1;
        while(i < j){
            if(s2[i] == s2[j]){
                i++;
                j--;
            }
            else{
                break;
            }
        }

        if(i >= j) 
            cout << s << "\n";
        else{
            i--, j++;
            string a, b, m, m2, best1, best2;
            copiar(s2, a, 1, i);
            copiar(s2, b, j, s2.size() - 2);
            copiar(s2, m, i + 1, j - 1);
            
            int ini = 0, fim = 0;

            while(fim < (int)m.size()){
                if(palind(m, ini, fim))
                    copiar(m, best1, ini, fim);
                fim++;
            }


            ini = m.size() - 1, fim = m.size() - 1;

            while(ini >= 0){
                if(palind(m, ini, fim))
                    copiar(m, best2, ini, fim);
                ini--;
            }

            cout << a;
            if(best1.size() > best2.size()) cout << best1;
            else cout << best2;
            cout << b << "\n";
        }
    }

    return 0;   
}
