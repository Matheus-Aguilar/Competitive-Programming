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

struct Character{
    int i, j, a;
    Character(int _i = 0, int _j = 0, int _a = 0) : i(_i), j(_j), a(_a){}
    bool operator<(const Character &m) const{
        if(a != m.a) return a > m.a;
        if(i != m.i) return i < m.i;
        return j < m.j;
    }
};

int check(int i, int j, set<Character> &s){
    for(set<Character>::iterator it = s.begin(); it != s.end(); it++)
        if(i != it->i && j != it->j)
            return it->a;
}

int main(){
    optimize;
    
    set<Character> s;

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int a;
            cin >> a;
            s.emplace(i, j, a);
        }
    }

    Character c = *s.begin(), c1 = *s.begin(), c2 = *s.begin();

    for(set<Character>::iterator it = s.begin(); it != s.end(); it++){
        if(c.i != it->i){
            c1 = *it;
            break;
        }
    }

    for(set<Character>::iterator it = s.begin(); it != s.end(); it++){
        if(c.j != it->j){
            c2 = *it;
            break;
        }
    }

    if(check(c.i, c1.j, s) < check(c2.i, c.j, s))
        cout << c.i << " " << c1.j << "\n";
    else
        cout << c2.i << " " << c.j << "\n";

    return 0;   
}
