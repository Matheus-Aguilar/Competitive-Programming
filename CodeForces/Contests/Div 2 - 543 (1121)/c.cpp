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

int p[160000];
int l[1100];
int r[1100];

int main(){
    optimize;
    
    int n, k;
    cin >> n >> k;

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < k; i++)
        pq.push(0);

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        
        int t = pq.top();
        pq.pop();
        
        l[i] = t;
        r[i] = t + a[i] - 1;
        p[r[i] + 1]++;
    
        pq.push(r[i] + 1);
    }

    for(int i = 1; i < 160000; i++)
        p[i] += p[i - 1];
    for(int i = 1; i < 160000; i++)
        p[i] = (1000 * p[i] + 5 * n)/(10 * n);
    
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = l[i], t = 1; j <= r[i]; j++, t++){
            if(t == p[j]){
                ans++;
                break;
            }
        }
    }

    cout << ans << "\n";

    return 0;   
}
