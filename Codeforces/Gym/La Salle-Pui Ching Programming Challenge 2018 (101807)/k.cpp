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

void getPicks(int d, int p[7], int &s){
    s = 0;
    memset(p, 0, sizeof(int) * 7);

    if(d == 0){
        p[0] = p[1] = 1;
        p[2] = p[4] = 1;
        p[5] = p[6] = 1;
    }
    else if(d == 1){
        p[5] = p[6] = 1;
    }
    else if(d == 2){
        p[1] = 1;
        p[2] = p[3] = p[4] = 1;
        p[5] = 1;
    }
    else if(d == 3){
        p[2] = p[3] = p[4] = 1;
        p[5] = p[6] = 1;
    }
    else if(d == 4){
        p[0] = 1;
        p[3] = 1;
        p[5] = p[6] = 1;
    }
    else if(d == 5){
        p[0] = 1;
        p[2] = p[3] = p[4] = 1;
        p[6] = 1;
    }
    else if(d == 6){
        p[0] = p[1] = 1;
        p[2] = p[3] = p[4] = 1;
        p[6] = 1;
    }
    else if(d == 7){
        p[2] = 1;
        p[5] = p[6] = 1;
    }
    else if(d == 8){
        p[0] = p[1] = 1;
        p[2] = p[3] = p[4] = 1;
        p[5] = p[6] = 1;
    }
    else if(d == 9){
        p[0] = 1;
        p[2] = p[3] = p[4] = 1;
        p[5] = p[6] = 1;
    }

    for(int i = 0; i < 7; i++)
        s += p[i];
}

bool canMerge(int p1[7], int p2[7]){
    return (p2[0] == p1[5] && p2[1] == p1[6]);
}

int solve(int x){
    
    int d1 = (x / 10) % 10, d2 = x % 10;
    int p1[7], p2[7];
    int s1, s2;

    getPicks(d1, p1, s1);
    getPicks(d2, p2, s2);

    if(d1 != 1 && canMerge(p1, p2))
        return s1 + s2 - p1[5] - p1[6];
    else
        return s1 + s2;
}

int main(){
    optimize;

    int T, q[100];
    cin >> T;

    ms(q, -1);

    while(T--){
        int x;
        cin >> x;

        if(q[x] == -1)
            q[x] = solve(x);
        
        cout << q[x] << "\n";
    }
    
    return 0;   
}
