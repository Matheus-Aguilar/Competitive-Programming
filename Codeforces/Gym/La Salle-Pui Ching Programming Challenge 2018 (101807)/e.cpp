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

bool check(vector<ll> &a){

    ll sum = 0;

    for(int i = 0; i < a.size() && sum <= 99999999 && sum >= 0; i++)
        sum += a[i];

    return sum <= 99999999 && sum >= 0;
}

int main(){
    optimize;

    int n;
    cin >> n;

    vector<ll> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(all(a));

    do{
        if(check(a)){
            for(int i = 0; i < n; i++)
                cout << a[i] << "\n";
            return 0;
        }
    } while(next_permutation(all(a)));

    cout << "Error" << "\n";
    
    return 0;   
}
