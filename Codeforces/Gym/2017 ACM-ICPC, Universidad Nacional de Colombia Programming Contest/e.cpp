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
#define MAXN 100100

using namespace std;

struct KMP{
    
    string w;
    vector<int> lps;
    
    KMP(string &_w){
        w = _w;
        lps.assign(w.size() + 1, -1);
        
        for(int i = 0, j = -1; i < (int)w.size();){
            
            while(j >= 0 && w[i] != w[j])
                j = lps[j];
            
            lps[++i] = ++j;
        }
    }

    int count(string &s){

        if(s.size() < w.size()) 
            return 0;
        
        int cont = 0;

        for(int i = 0, j = 0; i < (int) s.size(); ++i){
            
            while(j >= 0 && s[i] != w[j])
                j = lps[j];
            
            ++j;
            
            if(j == (int) w.size()){
                j = lps[j];
                cont++;
            }
        }

        return cont;
    }
};

bool check(int m, string &s, string &w, int k){
    string sub = w.substr(0, m);
    
    KMP kmp(sub);
    
    return kmp.count(s) >= k;
}

int binSearch(int l, int r, string &s, string &w, int k){
    while(l < r){
        int m = l + (r - l)/2;

        if(check(m, s, w, k))
            l = m + 1;
        else
            r = m;
    }
    return l - 1;
}

int main(){
    optimize;

    int k, best;
    string s, w;

    getline(cin, s);
    getline(cin, w);
    cin >> k;

    best = binSearch(1, w.size() + 1, s, w, k);

    cout << (best == 0 ? "IMPOSSIBLE" : w.substr(0, best)) << "\n";
    
    return 0;   
}
