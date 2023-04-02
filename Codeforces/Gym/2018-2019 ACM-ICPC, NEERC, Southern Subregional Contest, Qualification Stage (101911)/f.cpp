#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long
#define MAXN 1000100

using namespace std;

int ans[MAXN], cnt[MAXN], bit[MAXN];

int calcLuck(int x){
    
    int c1 = 0, c2 = 0;
    
    for(int i = 0; i < 3; i++){
        c1 += x % 10;
        x /= 10;
    }

    for(int i = 0; i < 3; i++){
        c2 += x % 10;
        x /= 10;
    }

    return abs(c1 - c2) + 1;
}

int query(int x){
    int sum = 0;
    while(x > 0){
        sum += bit[x];
        x -= -x & x;
    }
    return sum;
}

void update(int x, int v){
    while(x < MAXN){
        bit[x] += v;
        x += -x & x;
    }
}

void precalc() {
    for(int i = 0; i < MAXN; i++){
        cnt[i] = calcLuck(i);
        ans[i] = query(cnt[i] - 1);
        update(cnt[i], 1);
    }
}

int main() {
    optimize;

    precalc();

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }

    return 0;
}