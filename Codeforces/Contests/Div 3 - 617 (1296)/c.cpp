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

struct hasher{
    size_t operator()(const pii &p) const{
        return 100000LL * p.first + p.second;
    }
};

int main(){
    optimize;

    int t;
    cin >> t;
    while(t--){
        unordered_map<pii, int, hasher> visit;
        int n;
        string s;
        cin >> n >> s;

        int best = INF;
        pii interval;
        visit[pii(0, 0)] = 0;

        int x = 0, y = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'L') --x;
            else if(s[i] == 'R') ++x;
            else if(s[i] == 'U') ++y;
            else --y;

            if(visit.find(pii(x, y)) != visit.end()){
                int pos = visit[pii(x, y)];
                if(best > i + 1 - pos){
                    best = i + 1 - pos;
                    interval.first = pos;
                    interval.second = i;
                }
            }
            visit[pii(x, y)] = i + 1;
        }

        if(best != INF)
            cout << interval.first + 1 << " " << interval.second + 1 << "\n";
        else
            cout << -1 << "\n";
    }
    return 0;   
}
