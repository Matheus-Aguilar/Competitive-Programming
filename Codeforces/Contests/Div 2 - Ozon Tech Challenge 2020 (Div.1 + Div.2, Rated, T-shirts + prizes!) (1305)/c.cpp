#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

int bruteForce(vector<int> &a, int m){
    
    int ans = 1;
    
    for(int i = 0; i < a.size(); i++){
        for(int j = i + 1; j < a.size(); j++){
            ans *= abs(a[i] - a[j]) % m;
            ans %= m;
        }
    }
    return ans;
}

int main(){
    optimize;

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(n > m)
        cout << 0 << "\n";
    else
        cout << bruteForce(a, m) << "\n";
    return 0;   
}
