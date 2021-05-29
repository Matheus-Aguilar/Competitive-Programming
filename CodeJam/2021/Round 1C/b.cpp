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

vector<string> r;

bool cmp(const string &a, const string &b){
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

void precalc(){
    for(int d = 2; d <= 8; d++){
        for(int i = 1; i < 1000; i++){
            
            string s = "";

            for(int j = 0; j < d; j++)
                s += to_string(i + j);

            if(s.size() > 8)
                break;
            
            r.push_back(s);
        }
    }

    sort(all(r), cmp);
}

int main(){
    optimize;

    precalc();

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){
       
        int y;
        string ans;

        cin >> y;

        ans = *upper_bound(all(r), to_string(y), cmp);

        cout << "Case #" << t << ": " << ans << "\n";
    }
    
    return 0;   
}
