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

int main(){
    optimize;

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> ans;

    iota(all(a), 1);

    bool mode = true;
    
    int i = 0, j = n -1;
    for(int x = 0; x < k; x++){
        if(mode){
            ans.push_back(a[i]);
            i++;
        }
        else{
            ans.push_back(a[j]);
            j--;
        }
        mode = !mode;
    }

    if(!mode){
        for(int x = i; x <= j; x++){
            ans.push_back(a[x]);
        }
    }
    else{
        for(int x = j; x >= i; x--){
            ans.push_back(a[x]);
        }
    }

    for(int k = 0; k < n; k++)
        cout << ans[k] << " ";
    cout << "\n";

    return 0;   
}
