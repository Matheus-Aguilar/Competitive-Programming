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
#define MAXN 200200

using namespace std;

int n;
vector<int> nums[MAXN];

bool check(vector<int> &a){
    for(int i = 1; i < a.size(); i++){
        if(a[i - 1] > a[i]){
            return false;
        }
    }
    return true;
}

int main(){
    optimize;

    cin >> n;

    for(int i = 0; i < n; i++){
        int a, c;
        cin >> a >> c;
        nums[c].push_back(a);
    }

    bool ans = true;

    for(int i = 0; i < MAXN; i++){
        ans &= check(nums[i]);
    }

    cout << (ans ? "YES" : "NO") << "\n";
    
    return 0;   
}
