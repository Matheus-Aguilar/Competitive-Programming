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

int solve(vector<int> &a, vector<int> &b){
    vector<int> p(a.size() + 1, 0);


    for(int i = 1; i <= a.size(); i++){
        
        p[i] = p[i - 1];
        
        if(binary_search(all(b), a[i - 1]))
            p[i]++;
    }


    int best = 0;

    for(int i = 0; i < b.size(); i++){
        int cnt = upper_bound(all(a), b[i]) - a.begin();
        int sum = (cnt <= a.size() ? p[a.size()] - p[cnt] : 0);
        
        sum += i + 1;
        sum -= lower_bound(all(b), b[i] - cnt + 1) - b.begin();

        best = max(best, sum);
    }

    return best;
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        vector<int> b(m);

        vector<int> aPos, bPos, aNeg, bNeg;

        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < m; i++)
            cin >> b[i];
        
        for(int i = 0; i < n; i++){
            if(a[i] < 0) 
                aNeg.push_back(-a[i]);
            else 
                aPos.push_back(a[i]);
        }

        for(int i = 0; i < m; i++){
            if(b[i] < 0) 
                bNeg.push_back(-b[i]);
            else 
                bPos.push_back(b[i]);
        }

        reverse(all(aNeg));
        reverse(all(bNeg));

        cout << solve(aPos, bPos) + solve(aNeg, bNeg) << "\n";
    }
    
    return 0;   
}
