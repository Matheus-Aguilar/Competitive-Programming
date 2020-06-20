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

    int g;
    cin >> g;

    while(g--){
        int n, m, x;
        cin >> n >> m >> x;

        vector<int> s1(n + 1, 0);
        vector<int> s2(m + 1, 0);

        for(int i = 1; i <= n; i++)
            cin >> s1[i];
        for(int i = 1; i <= m; i++)
            cin >> s2[i];

        int i = 0, j = 0, sum = 0, cont = 0, best;
        while(i < n && sum + s1[i + 1] <= x){
            sum += s1[++i];
            cont++;
        }

        best = cont;
        
        while(i >= 0 && j < m){
            if(sum + s2[j + 1] <= x){
                sum += s2[++j];
                cont++;
            }
            else{
                sum -= s1[i--];
                cont--;
            }
            best = max(best, cont);
        }

        cout << best << "\n";
    }
    
    return 0;   
}
