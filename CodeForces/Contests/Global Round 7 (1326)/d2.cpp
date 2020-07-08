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
#define MAXN 1000100

using namespace std;

ll p1[4 * MAXN], m1 = 1000000207;
ll p2[4 * MAXN], m2 = 1000000123;

struct Hash{
    vector<ll> h1;
    vector<ll> h2;

    Hash(string &s){
        h1.resize(s.size());
        h2.resize(s.size());

        int l = (int)(s[0] - 'a');
        h1[0] = (l * p1[0]) % m1;
        h2[0] = (l * p2[0]) % m2;

        for(int i = 1; i < s.size(); i++){
            l = (int)(s[i] - 'a');
            h1[i] = (h1[i - 1] + (l * p1[i]) % m1) % m1;
            h2[i] = (h2[i - 1] + (l * p2[i]) % m2) % m2;
        }
    }

    pair<ll, ll> getHash(int l, int r, int ajuste){
        if(l - 1 < 0){
            ll sum1 = (h1[r] * p1[ajuste]) % m1;
            ll sum2 = (h2[r] * p2[ajuste]) % m2;
            return make_pair(sum1, sum2);
        }
        else{
            ll sumR1 = (h1[r] * p1[ajuste]) % m1;
            ll sumL1 = (h1[l - 1] * p1[ajuste]) % m1;
            ll sumR2 = (h2[r] * p2[ajuste]) % m2;
            ll sumL2 = (h2[l - 1] * p2[ajuste]) % m2;
            ll sum1 = (sumR1 - sumL1 + m1) % m1;
            ll sum2 = (sumR2 - sumL2 + m2) % m2;
            return make_pair(sum1, sum2);
        }
    }
};

void copiar(string &a, string &b, int ini, int fim){
    b = "";
    for(int i = ini; i <= fim; i++)
        b += a[i];
}

void preCalc(){
    p1[0] = 73;
    p2[0] = 89;

    for(int i = 1; i < 4 * MAXN; i++){
        p1[i] = (p1[i - 1] * p1[0]) % m1;
        p2[i] = (p2[i - 1] * p2[0]) % m2;
    }
}

int main(){
    optimize;

    preCalc();

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
            
            m2 = m;
            reverse(all(m2));

            Hash h1(m);
            Hash h2(m2);
            int n = m.size() - 1;

            int j, k;

            for(int i = 0; i < n; i++){
                if(h1.getHash(0, i, n - i) == h2.getHash(n - i, n, 0)){
                    j = i;
                }
            }

            for(int i = 0; i < n; i++){
                if(h2.getHash(0, i, n - i) == h1.getHash(n - i, n, 0)){
                    k = i;
                }
            }

            copiar(m, best1, 0, j);
            copiar(m2, best2, 0, k);

            cout << a;
            if(best1.size() > best2.size()) cout << best1;
            else cout << best2;
            cout << b << "\n";
        }
    }

    return 0;   
}
