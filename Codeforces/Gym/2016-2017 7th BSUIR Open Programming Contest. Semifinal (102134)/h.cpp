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
#define MAXN 10010

using namespace std;

int a[MAXN];
ll c[30], s[30], p[30];

int main(){
    optimize;

    p[0] = 1;

    for(int i = 1; i < 30; i++)
        p[i] = (p[i - 1] << 1);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    
        for(int j = 0; j < 30; j++){
            if(a[i] & p[j])
                c[j]++;
        }
    }

    for(int i = 0; i < 30; i++){
        //1 element
        s[i] += c[i];

        //2 element
        s[i] += 3 * c[i] * (c[i] - 1);
        s[i] += 3 * c[i] * (n - c[i]);

        //3 element
        s[i] += c[i] * (c[i] - 1) * (c[i] - 2);
        s[i] += 3 * c[i] * (n - c[i]) * (n - c[i] - 1);
    }

    ll sum = 0;

    for(int i = 0; i < 30; i++){
        sum += s[i] * p[i];
    }
    
    cout << sum << "\n";
    
    return 0;   
}
