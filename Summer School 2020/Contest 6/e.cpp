#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAXN 5010
#define INF 0xffffff

using namespace std;

pair<int, int> s[MAXN];
int p[MAXN];
int r[MAXN];
int ans[MAXN];
int closed[MAXN];

int main(){
    optimize;

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> s[i].first;
        s[i].second = i;
    }
    for(int i = 0; i < m; i++)
        cin >> p[i];
    for(int i = 0; i < m; i++)
        cin >> r[i];

    sort(s, s + n, greater<pair<int, int>>());

    for(int i = 0; i < n; i++){

        int best_price = INF;
        int cheapest = -1;

        for(int j = 0; j < m; j++){
            if(!closed[j] && s[i].first <= p[j]){
                if(best_price > r[j]){
                    best_price = r[j];
                    cheapest = j;
                }
            }
        }

        if(cheapest == -1){
            cout << "impossible" << "\n";
            return 0;
        }

        ans[s[i].second] = cheapest;
        closed[cheapest] = true;
    }

    for(int i = 0; i < n; i++)
        cout << ans[i] + 1 << " ";
    cout << "\n";
}