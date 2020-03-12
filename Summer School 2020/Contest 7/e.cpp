#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define MAXN 100010

using namespace std;

int nums[MAXN];

int main(){
    optimize;
    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums, nums + n);

    int ans = n;

    for(int i = 1; i < n; i++)
        ans = min(ans, (n - i - 1) + nums[i]);

    cout << ans << "\n";

    return 0;
}
