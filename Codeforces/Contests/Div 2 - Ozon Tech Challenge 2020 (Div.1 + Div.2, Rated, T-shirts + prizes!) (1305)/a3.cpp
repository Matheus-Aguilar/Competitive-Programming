#include<bits/stdc++.h>
#define optimize ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define INF 1000000000
#define pii pair<int, int>

using namespace std;

bool check(int x, int m){
    return x <= m;
}

int binSearch(int start, int end, int m){
    while(start < end){
        int middle = start + (end - start)/2;
        if(check(middle, m))
            start = middle + 1;
        else
            end = middle;
    }
    return start - 1;
}

int main(){
    optimize;

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int ans, sum = 0;
        cin >> ans;
        while(--n){
            int x;
            cin >> x;
            sum += x;
        }

        cout << ans + binSearch(0, sum + 1, m - ans) << "\n";
    }
    
    return 0;   
}
