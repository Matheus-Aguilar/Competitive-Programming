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
        int n, k = 0;
        cin >> n;
        vector<int> t(n);
        vector<int> c(n, 0);
        for(int i = 0; i < n; i++) 
            cin >> t[i];
        
        stack<int> st;
        
        for(int i = 0; i < n; i++){
            if(!c[i]){
                c[i] = 1;
                st.push(i);
            }
            while(!st.empty()){
                int cur = st.top();
                st.pop();
                int prv = (cur - 1 + n) % n;
                int nxt = (cur + 1) % n;

                if(t[cur] != t[prv]){
                    if(!c[prv]){
                        c[prv] = (c[cur] == 1 ? 2 : 1);
                        st.push(prv);
                    }
                    else if(c[cur] == c[prv]){
                        c[prv] = 3;
                    }
                }

                if(t[cur] != t[nxt]){
                    if(!c[nxt]){
                        c[nxt] = (c[cur] == 1 ? 2 : 1);
                        st.push(nxt);
                    }
                    else if(c[cur] == c[nxt]){
                        c[nxt] = 3;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++)
            k = max(k, c[i]);
        cout << k << "\n";
        for(int i = 0; i < n; i++)
            cout << c[i] << " ";
        cout << "\n";
    }

    return 0;   
}
