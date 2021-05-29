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
#define MAXN 200010

using namespace std;

int n;
int v[MAXN][3];

bool win(int i, int j){
    int points = 0;
    if(v[i][0] > v[j][0])
        points++;
    if(v[i][1] > v[j][1])
        points++;
    if(v[i][2] > v[j][2])
        points++;
    return points >= 2;
}

int main(){
    optimize;

    cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    
    int weak = 0;
    
    for(int i = 1; i < n; i++){   
        if(win(weak, i)){
            weak = i;
        }
    }
    
    for(int i = 0; i < n && weak != -1; i++){
        if(i != weak && win(weak, i)){
            weak = -1;
        }
    }
    
    if(weak != -1)
        cout << 1 << "\n" << weak + 1 << "\n";
    else
        cout << 0 << "\n";
    
    return 0;   
}
