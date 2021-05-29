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

ll dist[(1 << 21)];

int num(const string &s){
    
    int sum = 0;

    for(int i = s.size() - 1, j = 1; i >= 0; i--){
        if(s[i] == '1')
            sum |= j;
        j <<= 1;
    }

    return sum;
}

void mult(string &s){
    if(s[0] != '0')
        s.push_back('0');
}

void neg(string &s){
    
    for(int i = 0; i < s.size(); i++)
        s[i] = (s[i] == '0' ? '1' : '0');
    
    reverse(all(s));

    while(s.size() > 1 && s.back() == '0')
        s.pop_back();
    
    reverse(all(s));
}

void bfs(const string &s){
    
    queue<string> q;

    int ns = num(s);

    q.push(s);
    dist[ns] = 0;
    
    while(!q.empty()){
        
        string u = q.front();
        q.pop();

        int nu = num(u);
        
        string v1 = u, v2 = u;

        mult(v1);
        neg(v2);

        int nv1 = num(v1), nv2 = num(v2);

        if(nv1 < (1 << 21) && dist[nv1] == INFLL){
            dist[nv1] = dist[nu] + 1;
            q.push(v1);
        }

        if(dist[nv2] == INFLL){
            dist[nv2] = dist[nu] + 1;
            q.push(v2);
        }
    }
}

int main(){
    optimize;

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){
       
        string s, e;
        cin >> s >> e;

        ms(dist, INF);

        bfs(s);

        ll ans = dist[num(e)];

        if(ans != INFLL)
            cout << "Case #" << t << ": " << ans << "\n";
        else
            cout << "Case #" << t << ": " << "IMPOSSIBLE" << "\n";
    }
    
    return 0;   
}
