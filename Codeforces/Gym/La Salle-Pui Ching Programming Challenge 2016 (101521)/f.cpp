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

bool leap(int y){
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

struct Date{
    int d, m, y;
    Date() {}
    Date(int _d, int _m, int _y) : d(_d), m(_m), y(_y) {}
    bool operator==(const Date &dt) { return d == dt.d && m == dt.m; }
    void inc(){
        d++;

        if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
            if(d > 31){
                d = 1;
                m++;
            }
        }
        
        if(m == 4 || m == 6 || m == 9 || m == 11){
            if(d > 30){
                d = 1;
                m++;
            }
        }

        if(m == 2){
            if((d > 28 && !leap(y)) || d > 29){
                d = 1;
                m++;
            }
        }

        if(m > 12){
            m = 1;
            y++;
        }
    }
};

int main(){
    optimize;

    int cont = 0, special = 0;
    char aux;
    Date now, init, alice, bob;

    cin >> init.d >> aux >> init.m >> aux >> init.y;
    cin >> alice.d >> aux >> alice.m;
    cin >> bob.d >> aux >> bob.m;

    now = init;
    now.inc();

    for(int i = 1; i <= 2048; i++){
        if(init == now || alice == now || bob == now || i % 100 == 0)
            special++;
        now.inc();
    }

    cout << special << "\n";
    
    return 0;   
}
