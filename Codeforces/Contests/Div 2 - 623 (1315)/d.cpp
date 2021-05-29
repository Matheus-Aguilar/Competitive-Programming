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

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> t(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> t[i];

    ll ans = 0;
    map<int, vector<int>> m;
    set<int> s;

    for(int i = 0; i < n; i++){
        m[a[i]].push_back(t[i]);
        s.insert(a[i]);
    }

    priority_queue<int> pq;
    ll sum = 0;
    int pos = 0;

    while(!s.empty() || !pq.empty()){
        pos++;
        ans += sum;
        if(pq.empty()){
            pos = *s.begin();
            auto it = m.find(pos);
            for(int i:it->second){
                pq.push(i);
                sum += i;
            }
            sum -= pq.top();
            pq.pop();
            s.erase(s.begin());
        }
        else{
            auto it = m.find(pos);
            if(it != m.end()){
                for(int i:it->second){
                    pq.push(i);
                    sum += i;
                }
                s.erase(pos);
            }
            sum -= pq.top();
            pq.pop();
        }
    }

    cout << ans << "\n";
    
    return 0;   
}
