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
#define MAXN 200

using namespace std;

int q, n, qa[MAXN], na[MAXN], freq[10], sum[10];

void countDigits(int a[], int x){
    if(x == 0)
        a[0]++;
    else {
        while(x > 0){
            a[x % 10]++;
            x /= 10;
        }
    }
}

int main(){
    optimize;
    
    cin >> q >> n;

    for(int i = 0; i < q; i++)
        cin >> qa[i];
    
    for(int i = 0; i < n; i++){
        cin >> na[i];
        freq[na[i]]++;
    }

    int sz = 0, best = -1;

    for(int i = 0; i < (1 << q); i++){
        memset(sum, 0, sizeof(int) * 10);
        
        for(int j = 0; j < q; j++){
            if(i & (1 << j)){
                countDigits(sum, qa[j]);
            }
        }

        bool ok = true;
        for(int j = 0; j < 10 && ok; j++){
            ok &= (sum[j] <= freq[j]);
        }

        if(ok){
            int newSz = __builtin_popcount(i);
            if(newSz >= sz){
                sz = newSz;
                best = i;
            }
        }
    }

    cout << sz << "\n";

    for(int i = 0; i < q; i++){
        if(best & (1 << i)){
            cout << qa[i] << " ";
        }
    }

    cout << "\n";

    return 0;   
}
