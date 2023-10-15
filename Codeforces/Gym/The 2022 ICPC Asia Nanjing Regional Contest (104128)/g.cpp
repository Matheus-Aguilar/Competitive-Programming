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
#define MAXN 1000100

using namespace std;

int n, a[MAXN];

bool check(int x){

    int total = 1;
    int cnt = 0;

    for(int i = 1; i <= n; i++){
        if(a[i] == 1){
            total++;
        }
        else if(a[i] == -1){
            total--;
        }
        else{

            if(cnt < x)
                total++;
            else
                total--;
            cnt++;
        }

        if(total <= 0)
            return false;
    }

    return total > 0;
}

int binSearch(int l, int r){
    while(l < r){
        int m = l + (r - l) / 2;
        if(check(m))
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int cnt = 0;
        cin >> n;

        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(a[i] == 0)
                cnt++;
        }

        int x = binSearch(0, cnt);
        cnt = 0;

        for(int i = 1; i <= n; i++){
            if(a[i] == 0){
                if(cnt < x){
                    a[i] = 1;
                    cnt++;
                } else {
                    a[i] = -1;
                }
            }
        }

        int p = 1, q = 1;

        for(int i = 1; i <= n; i++){
            if(a[i] == 1){
                p++;
                q++;
            } else {
                q--;
            }
        }

        if(!check(0))
            cout << -1 << "\n";
        else{
            int g = __gcd(p, q);
            cout << p / g << " " << q / g << "\n";
        }
    }
    
    return 0;   
}
