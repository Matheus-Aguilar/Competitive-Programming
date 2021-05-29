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

    int t;
    cin >> t;

    map<int, int> m;
    priority_queue<int> pq;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        
        m.clear();

        for(int i = 0; i < n; i++){
            cin >> a[i];
            m[a[i]]++;
        }

        sort(all(a));
        a.erase(unique(all(a)), a.end());

        for(int i = 0; i < a.size(); i++){
            pq.push(m[a[i]]);
        }

        while(pq.size() > 1){
            
            int low, high;
            
            high = pq.top();
            pq.pop();

            low = pq.top();
            pq.pop();

            if(high > 1)
                pq.push(high - 1);
            if(low > 1)
                pq.push(low - 1);
        }

        if(pq.size() == 0)
            cout << 0 << "\n";
        else{
            cout << pq.top() << "\n";
            pq.pop();
        }
    }
    
    return 0;   
}
