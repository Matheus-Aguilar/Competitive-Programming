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

void solve(queue<int> &q, int &T){
    
    int init = T;

    if(q.front() > T){
        T = q.front();
    }

    while(!q.empty() && T >= q.front()){
        int Q = q.front();

        if(Q < init){
            Q = init;
        }

        T = max( Q+ 10, T);
        q.pop();
    }
}

int main(){
    optimize;
    
    int n;
    cin >> n;

    int T = 0;
    vector<int> t(n);
    vector<int> d(n);

    queue<int> q1, q2;

    for(int i = 0; i < n; i++){
        cin >> t[i] >> d[i];

        if(d[i] == 0)
            q1.push(t[i]);
        else
            q2.push(t[i]);
    }

    while(!q1.empty() || !q2.empty()){

        if(q2.empty() || (!q1.empty() && q1.front() < q2.front())){
            solve(q1, T);
        }
        else{
            solve(q2, T);
        }
    }

    cout << T << "\n";

    return 0;   
}
