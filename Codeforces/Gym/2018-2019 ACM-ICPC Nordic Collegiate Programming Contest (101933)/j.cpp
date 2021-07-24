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

inline ll sum(ll x){
    return (x * (x - 1)) / 2;
}

int main(){
    optimize;

    ll a, b, c, d, one = -1, zero = -1;
    cin >> a >> b >> c >> d;

    for(ll i = 1; sum(i) <= a; i++){
        if(sum(i) == a){
            zero = i;
            break;
        }
    }

    for(ll i = 1; sum(i) <= d; i++){
        if(sum(i) == d){
            one = i;
            break;
        }
    }

    if(one == -1 || zero == -1 || (zero == 0 && one == 0)){
        cout << "impossible" << "\n";
    }
    else{

        if(a == 0 && b == 0 && c == 0){
            zero = 0;
        }
        else if(b == 0 && c == 0 && d == 0){
            one = 0;
        }

        string s = "";

        for(int i = 0; i < zero; i++)
            s.push_back('0');
        for(int i = 0; i < one; i++)
            s.push_back('1');

        ll contB = zero * one, contC = 0;
        
        for(int i = zero; i < s.size(); i++){
            ll diff = contB - b;

            if(diff > 0){
                ll mov = min(zero, diff);

                swap(s[i], s[i - mov]);
                contB -= mov;
                contC += mov; 
            }
        }

        if(contB == b && contC == c){
            cout << s << "\n";
        }
        else{
            cout << "impossible" << "\n";
        }
    }

    return 0;   
}
