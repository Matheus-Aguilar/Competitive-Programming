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
#define MAXN 7070

using namespace std;

int n, k;
int a[MAXN];
set<pii> elem;

int main(){
    optimize;

    cin >> n >> k;
    
    int total = (n + 1) * n / 2;

    for(int i = 0; i < n; i++){
        cin >> a[i];
        elem.emplace(a[i], i);
    }

    bool ok = false;

    for(int i = 0; i < n && !ok; i++){
        
        elem.erase(make_pair(a[i], i));
        
        int pos = 0;
        int total = (elem.size() + 1) * elem.size() / 2 + 1 + i;

        for(auto it : elem){
            if(it.first < a[i]){
                pos++;
            } else {
                break;
            }
        }

        if(k <= pos){
            pos = 0;
            
            for(auto it : elem){
                
                if(it.first < a[i]){
                    pos++;
                } else {
                    break;
                }

                if(pos == k){
                    reverse(a + i, a + it.second + 1);
                    ok = true;
                    break;
                }
            }

        } else if(k <= pos + total) {
            k -= pos;
        } else {

            k -= pos;
            k -= total;

            pos = 0;
        
            for(auto it : elem){
                
                if(it.first > a[i]){
                    pos++;
                }

                if(pos == k){
                    reverse(a + i, a + it.second + 1);
                    ok = true;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << a[i] << " \n"[i+1==n];
    }

    return 0;   
}
