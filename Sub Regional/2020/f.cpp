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

int g[2] = {0, 0}, p[2] = {0, 0};
bool s = false;

bool win(){
    return (g[0] >= 2 || g[1] >= 2);
}

void query(){
    if(win()){
        if(g[0] >= 2)
            cout << g[0] << " (winner) - " << g[1] << "\n";
        else
            cout << g[0] << " - " << g[1] << " (winner)\n";
    }
    else{
        if(!s)
            cout << g[0] << " (" << p[0] << "*)" << " - " << g[1] << " (" << p[1] << ")\n";
        else
            cout << g[0] << " (" << p[0] << ")" << " - " << g[1] << " (" << p[1] << "*)\n";
    }
}

int main(){
    optimize;

    string st;
    cin >> st;

    for(int i = 0; i < st.size(); i++){
        if(st[i] != 'Q' && !win()){
            if(st[i] == 'R')
                s = !s;
            p[s]++;

            if((p[s] >= 5 && p[s] - p[!s] >= 2) || p[s] == 10){
                g[s]++;
                p[s] = 0;
                p[!s] = 0;
            }
        }
        else if(st[i] == 'Q')
            query();
    }
    
    return 0;   
}