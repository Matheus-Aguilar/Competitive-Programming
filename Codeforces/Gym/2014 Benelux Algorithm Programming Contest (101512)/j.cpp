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

    int T;
    cin >> T;

    cout << T << "\n";

    while(T--){
        string s;
        cin >> s;

        pii dir = {0, 1};
        pii pos = {0, 0};
        pii low = {INF, INF};
        pii high = {-INF, -INF};

        vector<pii> path;
        path.push_back(pos);

        for(int i = 0; i < s.size(); i++){
            
            if(s[i] == 'B'){
                dir.first  = -dir.first;
                dir.second = -dir.second;
            }
            else if(s[i] == 'L'){
                swap(dir.first, dir.second);
                dir.first = -dir.first;
            }
            else if(s[i] == 'R'){
                swap(dir.first, dir.second);
                dir.second = -dir.second;
            }

            pos.first  += dir.first;
            pos.second += dir.second;

            path.push_back(pos);

            low.first  = min(low.first, pos.first);
            low.second = min(low.second, pos.second);
        }

        for(int i = 0; i < path.size(); i++){
            path[i].first  += 1 - low.first;
            path[i].second += -low.second;
            
            high.first  = max(high.first, path[i].first + 1);
            high.second = max(high.second, path[i].second + 1);
        }

        vector<string> grid(high.first + 1, string(high.second + 1, '#'));

        for(int i = 0; i < path.size(); i++){
            grid[path[i].first][path[i].second] = '.';
        }

        cout << grid.size() << " " << grid[0].size() << "\n";

        for(int i = 0; i < grid.size(); i++)
            cout << grid[i] << "\n";
    }
    
    return 0;   
}
