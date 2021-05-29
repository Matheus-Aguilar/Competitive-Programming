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
#define MAXN 100100
#define DEBU

using namespace std;

const int K = 150;

int n, d, a[MAXN];
double p[MAXN], p0[MAXN];
pii ans;

bool solve(double m){
    
    p[0] = 0.0;

    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + (a[i] - m);

    for(int i = 0; i < d; i++)
        p0[i] = 0.0;

    for(int i = d; i <= n; i++)
        p0[i] = min(p0[i - 1], p[i - d]);

    for(int i = d; i <= n; i++){
        if(p[i] - p0[i] >= 0){

            ans = make_pair(-1, i);
        
            for(int j = 0; j + d <= i; j++){
                if(p[i] - p[j] >= 0){
                    ans.first = j + 1;
                    return true;
                }
            }
        }
    }

    return false;
}

double binSearch(double l, double r){
    
    double m;
    
    for(int i = 0; i < K; i++){
        
        m = l + (r - l)/2;

        if(solve(m))
            l = m;
        else
            r = m;
    }

    return m;
}

int main(){
    optimize;
    
    cin >> n >> d;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    double avg = binSearch(0, 101);

    solve(avg);

    cout << ans.first << " " << ans.second << "\n";

    return 0;   
}
