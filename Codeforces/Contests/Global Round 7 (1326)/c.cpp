#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define PI 3.141592653589793238462643383279502884L
#define mod % 998244353
#define all(v) v.begin(), v.end()
#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

int main(){
    optimize;

    int n, k;
    ll total = 0, num = 1;
    cin >> n >> k;

    int menor = n - k + 1, maior = n;

    vector<int> a(n);
    vector<int> b;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = n; i > n - k; i--) total += i;

    int pos = -1;
    for(int i = 0; i < n; i++){
        if(menor <= a[i] && a[i] <= maior){
            if(pos != -1)
                b.push_back(i - pos);
            pos = i;
        }
    }

    for(int i = 0; i < b.size(); i++){
        num = (num * b[i]) mod;
    }

    cout << total << " " << num << "\n";


    return 0;   
}
