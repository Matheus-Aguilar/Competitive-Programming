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

ll twoPointers(vector<int> &a, ll sum){
    int i = 0, j = a.size() - 1;
    ll cont = 0;
    while(i < j){
        if(a[i] + a[j] > sum){
            j--;
        }
        else{
            cont += j - i;
            i++;
        }
    }
    return cont;
}

int main(){
    optimize;

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    ll ans = 0;

    for(int i = 0; i <= 26; i++){
        vector<int> module(n);
        for(int j = 0; j < n; j++)
            module[j] = a[j] % (2 << i);
        sort(all(module));
        ll ones = 0; 
        ones += twoPointers(module, (2 << i) - 1) - twoPointers(module, (1 << i) - 1);
        
        ones += twoPointers(module, (4 << i) - 2) - twoPointers(module, (2 << i) + (1 << i) - 1);
        ones &= 1;
        ans |= (ones << i);
    }
    cout << ans << "\n";
    
    return 0;   
}
