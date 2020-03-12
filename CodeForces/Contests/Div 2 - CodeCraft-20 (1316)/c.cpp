#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int main(){
    optimize;
    
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    vector<int> a(n);
    vector<int> b(m);

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int i = 0; i < m; i++)
        scanf("%d", &b[i]);

    int i = 0, j= 0;

    while(i <= n && a[i] % p == 0) i++;
    while(j <= m && b[j] % p == 0) j++;

    cout << i + j << "\n";

    return 0;   
}
