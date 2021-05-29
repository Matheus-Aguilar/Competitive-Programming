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
        
        int n;
        cin >> n;

        vector<int> a(2 * n);
        vector<pii> sol(n);
        multiset<int> s;

        for(int i = 0; i < 2 * n; i++){
            cin >> a[i];
            s.insert(a[i]);
        }

        sort(all(a));

        sol[0].first = a.back();
        s.erase(s.find(a.back()));

        bool ok = false;

        for(int i = 0; i < 2 * n - 1 && !ok; i++){
            
            ok = true;

            sol[0].second = a[i];
            s.erase(s.find(a[i]));
        
            int x = a.back();

            for(int j = 1; j < n && ok; j++){
                
                sol[j].first = *s.rbegin();
                s.erase(s.find(sol[j].first));

                multiset<int>::iterator it = s.find(x - sol[j].first);

                if(it != s.end()){
                    
                    sol[j].second = *it;
                    s.erase(it);

                    x = sol[j].first;
                }
                else{
                    ok = false;
                }
            }


            s.clear();

            for(int j = 0; j < 2 * n - 1; j++)
                s.insert(a[j]);
        }

        if(ok){
            cout << "YES" << "\n";
            cout << sol[0].first + sol[0].second << "\n";

            for(int i = 0; i < n; i++)
                cout << sol[i].first << " " << sol[i].second << "\n";
        }
        else{
            cout << "NO" << "\n";
        }
    }

    return 0;   
}
