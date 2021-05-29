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

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    size_t a, b;
    string s, h = "happiness", original;
    cin >> s;

    a = s.find(h);
    
    if(a != string::npos){
        
        b = s.find(h, a + 1);

        if(b == string::npos){
            cout << "YES" << "\n";
            cout << a + 1 << " " << a + 2 << "\n";
        }
        else{
            if(s.find(h, b + 1) == string::npos){
                cout << "YES" << "\n";
                cout << a + 1 << " " << b + 2 << "\n";
            }
            else{
                cout << "NO" << "\n";
            }
        }
    }
    else{

        a = 0, b = 0;

        do{
            swap(s[a], s[b]);
            a = rng() % s.size(), b = rng() % s.size();
            if(a == b) b = (b + 1) % s.size();
            swap(s[a], s[b]);
        } while(s.find(h) != string::npos);

        cout << "YES" << "\n";
        cout << a + 1 << " " << b + 1 << "\n";
    }
    
    return 0;   
}
