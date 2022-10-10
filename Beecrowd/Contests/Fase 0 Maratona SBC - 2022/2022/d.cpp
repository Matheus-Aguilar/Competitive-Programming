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

int pts[5];
int op[5];

int bt(int i, int j, string &s, string &t){
    
    if(j == t.size())
        return s.size() - i;
    if(i == s.size())
        return t.size() - j;
    
    int best = INF;
    
    if(s[i] == t[j])
        best = min(best, bt(i + 1, j + 1, s, t));
    else{
        best = min(best, 1 + bt(i + 1, j + 1, s, t));
        best = min(best, 1 + bt(i, j + 1, s, t));
        best = min(best, 1 + bt(i + 1, j, s, t));
    }

    return best;
}

int main(){
    optimize;

    int n;
    cin >> n;


    while(n--){
        string s;
        cin >> s;

        int best = INF;

        for(int i = 0; i < 5; i++){
            string t;
            cin >> t;
            op[i] = bt(0, 0, s, t);
            best = min(op[i], best);
        }

        for(int i = 0; i < 5; i++){
            if(best == op[i]){
                pts[i] += (best == 0 ? 10 : 5);
            }
        }
    }
    
    int best = *max_element(pts, pts + 5);
    bool first = true;

    cout << (best / 10) << "." << (best % 10) << "\n";

    for(int i = 0; i < 5; i++){
        if(best == pts[i]){
            if(!first)
                cout << " " << i + 1;
            else{
                cout << i + 1;
                first = false;
            }
        }
    }

    cout << "\n";

    return 0;   
}
