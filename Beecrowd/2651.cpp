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

struct KMP{
    string p;
    vector<int> st;

    KMP(const string &_p){
        p = _p;
        st.assign(p.size() + 1, -1);
        int i = 0, j = -1;
        while(i < p.size()){
            while(j >= 0 && p[i] != p[j])
                j = st[j];
            st[++i] = ++j;
        }
    }
    int count(const string &s){
        int i = 0, j = 0, cont = 0;
        while(i < s.size()){
            while(j >= 0 && s[i] != p[j])
                j = st[j];
            i++, j++;
            if(j == p.size()){
                cont++;
                j = st[j];
            }
        }
        return cont;
    }
};

int main(){
    optimize;
    
    string s;
    cin >> s;
    transform(all(s), s.begin(), [](unsigned char c){ return tolower(c); });
    KMP kmp("zelda");
    cout << (kmp.count(s) >= 1 ? "Link Bolado" : "Link Tranquilo") << "\n";

    return 0;   
}
