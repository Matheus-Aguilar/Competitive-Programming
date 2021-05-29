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
#define MAXN 1010
 
using namespace std;
 
int n, b, t[MAXN], z[MAXN], y[MAXN], c[MAXN];
 
bool solve(int T){
    
    ms(c, 0);

    int rem = b;
 
    for(int i = 0; i < n && rem > 0; i++){
        
        int tm = T, bal;

        while(tm >= t[i] && rem > 0){
            
            if(tm >= t[i] * z[i]){
                bal = min(z[i], rem);
                tm -= y[i];         
            }
            else{
                bal = min(tm / t[i], rem);
            }

            tm -= bal * t[i];
            c[i] += bal;
            rem -= bal;
        }
    }
 
    return rem == 0;
}
 
int binSearch(int l, int r){
    
    while(l < r){
        
        int m = l + (r - l)/2;
 
        if(solve(m))
            r = m;
        else
            l = m + 1;
    }
 
    return l;
}
 
int main(){
    optimize;
 
    cin >> b >> n;
 
    for(int i = 0; i < n; i++)
        cin >> t[i] >> z[i] >> y[i];
 
    int T = binSearch(0, INF);
 
    cout << T << "\n";
    
    solve(T);
 
    for(int i = 0; i < n; i++)
        cout << c[i] << " \n"[i==n-1];
 
    return 0;   
}