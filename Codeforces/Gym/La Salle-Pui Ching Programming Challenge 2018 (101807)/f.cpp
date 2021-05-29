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
#define MAXN 5010

using namespace std;

int n, a[MAXN], b[MAXN], p[MAXN], s[MAXN], c[MAXN], cat[MAXN];

int solveBest(int x){
    
    int best = 1;

    for(int i = 1; i <= n; i++){
        if(i == x)
            cat[i] = 0;
        else if(p[i] > p[x] + 3)
            cat[i] = 1;
        else if(p[i] + 1 > p[x] + 3)
            cat[i] = 2;
        else if(p[i] + 3 > p[x] + 3)
            cat[i] = 3;
        else
            cat[i] = 4;
    }

    for(int i = 1; i <= n; i++){
        if(cat[i] == 1)
            best++;
    }

    for(int i = 0; i < n / 2; i++){
        if(cat[a[i]] == 2 && cat[b[i]] == 2)
            best++;
        else if(cat[a[i]] == 2 && cat[b[i]] == 3)
            best++;
        else if(cat[a[i]] == 3 && cat[b[i]] == 2)
            best++;
    }

    return best;
}

int solveWorst(int x){
    
    int worst = n;

    for(int i = 1; i <= n; i++){
        if(i == x)
            cat[i] = 0;
        else if(p[i] >= p[x])
            cat[i] = 1;
        else if(p[i] + 1 >= p[x])
            cat[i] = 2;
        else if(p[i] + 3 >= p[x])
            cat[i] = 3;
        else
            cat[i] = 4;
    }

    for(int i = 1; i <= n; i++){
        if(cat[i] == 4)
            worst--;
    }

    for(int i = 0; i < n / 2; i++){
        if(cat[a[i]] == 2 && cat[b[i]] == 3)
            worst--;
        else if(cat[a[i]] == 3 && cat[b[i]] == 2)
            worst--;
        else if(cat[a[i]] == 3 && cat[b[i]] == 3)
            worst--;
    }

    return worst;
}

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n / 2; i++)
        cin >> a[i] >> b[i];
    
    for(int i = 1; i <= n; i++)
        cin >> p[i] >> s[i] >> c[i];

    for(int i = 1; i <= n; i++){
        cout << solveBest(i) << " " << solveWorst(i) << "\n";
    }
    
    return 0;   
}
