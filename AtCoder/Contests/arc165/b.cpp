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

    vector<int> a(n), b;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    b = a;
    sort(b.end() - k, b.end());

    bool ok = false;
    set<int> pq;

    for(int i = 0; i < n && !ok; i++){
        
        pq.insert(a[i]);
        
        if(pq.size() == k){

            ok = true;
            auto it = pq.begin();

            for(int j = i - k + 1; j <= i && ok; j++){
                if(*it < b[j]){
                    ok = false;
                    while(j >= i - k + 1){
                        pq.erase(a[j]);
                        j--;
                    }
                }
                else{
                    it++;
                }
            }
            
            if(ok){
                sort(a.begin() + i - k + 1, a.begin() + i + 1);
            }
        }
    }

    for(int i = 0; i < a.size(); i++)
        cout << a[i] << " \n"[i+1==a.size()];
    
    return 0;   
}
