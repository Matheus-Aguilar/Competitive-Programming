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

    string acu = "R", res = "";
    vector<string> s;

    s.push_back("R");
    s.push_back("P");
    s.push_back("S");

    for(int i = 3; i < n - 1; i += 2){
        s.push_back(s[i - 2] + s[i - 1] + acu);
        s.push_back(s[i - 1] + acu + s[i - 2]);
        acu += s[i - 2];
        acu += s[i - 1];
    }

    for(int i = 0; i < n; i++){
        //cout << s[i] << "\n";
        res += s[i];
    }

    for(int i = 0, j = 0; i < res.size(); i++){
        if(res[i] == 'R'){
            cout << (j % 3 ? "" : "\n") << i % 3 << " ";
            j++;
        }
    }

    cout << "\n";

    // vector<vector<int>> pos(3, vector<int>());

    // for(int i = 0; i < res.size(); i++){
    //     if(res[i] == 'R') pos[0].push_back(i);
    //     if(res[i] == 'P') pos[1].push_back(i);
    //     if(res[i] == 'S') pos[2].push_back(i);
    // }

    // for(int i = 0; i < 3; i++){
    //     cout << i << ": ";
    //     for(int j = 0; j < pos[i].size(); j++){
    //         cout << pos[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    return 0;   
}
