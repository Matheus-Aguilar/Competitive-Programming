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
 
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        if(n == 1){
            cout << (a[0] == k ? "yes" : "no") << "\n";
        }
        else if(find(all(a), k) == a.end()){
            cout << "no" << "\n";
        }
        else{
            bool ans = false;
            vector<int> pos;
            for(int i = 0; i < n && !ans; i++){
                if(a[i] >= k){
                    pos.push_back(i);
                    if(i == 0 && a[i + 1] >= a[i])
                        ans = true;
                    else if(i == n - 1 && a[i - 1] >= a[i])
                        ans = true;
                    else if((i > 0 && i < n -1) && (a[i - 1] >= a[i] || a[i + 1] >= a[i]))
                        ans = true;
                }
            }
 
            int dist = 1, cont = 0;
            for(int i = pos[0] + 2; i < n && !ans; i++){
                if(cont % 2 != 0 && a[i] < k){
                    dist++;
                }
                else if(a[i] >= k){
                    if(cont % 2 == 0)
                        dist--;
                    if(dist == 0)
                        ans = true;
                    dist = 1, cont = 0;
                    i++;
                    continue;
                }
                cont++;
            }
 
            dist = 1, cont = 0;
            for(int i = pos.back() - 2; i >= 0 && !ans; i--){
                if(cont % 2 != 0 && a[i] < k){
                    dist++;
                }
                else if(a[i] >= k){
                    if(cont % 2 == 0)
                        dist--;
                    if(dist == 0)
                        ans = true;
                    dist = 1, cont = 0;
                    i--;
                    continue;
                }
                cont++;
            }
 
            cout << (ans ? "yes" : "no") << "\n";
        }
    }
    
    return 0;   
}