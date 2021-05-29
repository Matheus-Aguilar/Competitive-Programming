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

const ll limit = (1LL << 32) - 1;

int main(){
    optimize;

    int l;
    cin >> l;

    ll x = 0;
    bool ok = true;
    stack<pair<ll, ll>> st;
    string op;

    st.emplace(1, 0);

    for(int i = 0; i < l && ok; i++){
        
        cin >> op;

        if(op == "for"){

            int n;
            cin >> n;

            st.emplace(n, 0);
        }
        else if(op == "end"){

            pair<ll, ll> p = st.top();
            st.pop();

            st.top().second += p.first * p.second;
        }
        else{
            st.top().second++;
        }

        if(st.top().second > limit)
            ok = false;
    }

    if(!ok)
        cout << "OVERFLOW!!!" << "\n";
    else
        cout << st.top().first * st.top().second << "\n";
    
    return 0;   
}
