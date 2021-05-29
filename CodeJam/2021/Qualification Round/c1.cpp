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

int cost(vector<int> a, int n){

    int ans = 0;

    for(int i = 0; i < n - 1; i++){
        for(int j = i; j < n; j++){
            if(a[j] == i + 1){
                ans += j - i + 1;
                reverse(a.begin() + i, a.begin() + j + 1);
                break;
            }
        }
    }

    return ans;
}

int main(){
    optimize;

    int T;
    cin >> T;

    for(int t = 1; t <= T; t++){
        
        int n, c;
        bool found = false;

        cin >> n >> c;

        vector<int> a(n);
        iota(all(a), 1);

        do{
            if(cost(a, n) == c){
                found = true;
                break;
            }
        } while(next_permutation(all(a)));

        cout << "Case #" << t << ": ";

        if(!found)
            cout << "IMPOSSIBLE" << "\n";
        else{
            for(int i = 0; i < n; i++)
                cout << a[i] << " \n"[i==n-1];
        }
    }
    
    return 0;   
}
