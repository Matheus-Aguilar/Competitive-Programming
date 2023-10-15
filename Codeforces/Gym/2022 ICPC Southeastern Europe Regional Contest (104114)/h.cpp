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

vector<pii> moves;
stack<int> s[3];

void move(int i, int j){
    moves.emplace_back(i + 1, j + 1);
    s[j].push(s[i].top());
    s[i].pop();
}

int main(){
    optimize;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        s[0].push(x);
    }

    for(int i = 0; i < n; i++){
        move(0, 1);
        
        int cnt = 0;
        while(!s[2].empty() && s[2].top() < s[1].top()){
            move(2, 0);
            cnt++;
        }

        move(1, 2);
    
        while(cnt > 0){
            move(0, 2);
            cnt--;
        }
    }

    cout << moves.size() << "\n";

    for(int i = 0; i < moves.size(); i++)
        cout << moves[i].first << " " << moves[i].second << "\n";
    
    return 0;   
}
