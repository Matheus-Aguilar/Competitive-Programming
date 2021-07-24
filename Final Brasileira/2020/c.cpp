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

ll solve(vector<int> &a){
    
    ll ans = 0, acc = 0;

    for(int i = 0; i < a.size(); i++){
        if(a[i] > 0){
            acc += a[i];
            a[i] = 0;
        }
        else{
            if(acc < abs(a[i])){
                a[i] += acc;
                acc = 0;
            }
            else{
                acc += a[i];
                a[i] = 0;
            }
        }
        ans += acc;
        cout << acc << "\n";
    }

    for(int i = 0; i < a.size(); i++){
        if(a[i] > 0){
            acc += a[i];
            a[i] = 0;
        }
        else{
            if(acc < abs(a[i])){
                a[i] += acc;
                acc = 0;
            }
            else{
                acc += a[i];
                a[i] = 0;
            }
        }
        ans += acc;
        cout << acc << "\n";
    }

    return ans;
}

int main(){
    optimize;
    
    int n;
    cin >> n;

    vector<int> a(n), ar;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int avg = 0;

    for(int i = 0; i < n; i++)
        avg += a[i];

    avg /= n;

    for(int i = 0; i < n; i++)
        a[i] -= avg;

    ar = a;
    reverse(all(ar));

    cout << max(solve(a), solve(ar)) << "\n";

    return 0;   
}
