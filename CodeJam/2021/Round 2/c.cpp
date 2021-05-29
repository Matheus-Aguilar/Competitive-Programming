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
#define MAXN 15

using namespace std;

int n, p[MAXN], v[MAXN];
ll sum;
vector<int> st;

void print(int p[], int N){
    for(int i = 0; i < N; i++)
        cout << p[i] << " ";
    cout << "\n";
}

void bt(int i){
    
    if(i == n){
        sum = (sum + 1) mod;
        return;
    }

    vector<int> aux = st;

    for(int j = i; j < n; j++){
        
        swap(p[i], p[j]);

        while(!st.empty() && st.back() < p[i])
            st.pop_back();
        
        st.push_back(p[i]);

        if(st.size() == v[i])
            bt(i + 1);
        
        st = aux;
        swap(p[i], p[j]);
    }
}

int main(){
    optimize;

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){
        
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> v[i];

        iota(p, p + n, 1);
        sum = 0;

        bt(0);

        cout << "Case #" << t << ": " << sum << "\n";
    }
    
    return 0;   
}
