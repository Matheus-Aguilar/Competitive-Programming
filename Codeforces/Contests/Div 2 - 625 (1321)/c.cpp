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

typedef list<char>::iterator iter;

int main(){
    optimize;
    
    int n, ans = 0;
    list<char> l;
    cin >> n;

    if(n == 1){
        cout << 0 << "\n";
        return 0;
    }

    for(int i = 0; i < n; i++){
        char c;
        cin >> c;
        l.push_back(c);
    }

    iter best = l.begin();
        
    while(l.begin() != prev(l.end()) && best != l.end()){
        
        best = l.end();
        
        for(iter it = l.begin(); it != l.end(); it++){
            if(it == l.begin()){
                if(*it - 1 == *next(it)){
                    if(best == l.end() || *best < *it)
                        best = it;
                }
            }
            else if(it == prev(l.end())){
                if(*it - 1 == *prev(it)){
                    if(best == l.end() || *best < *it)
                        best = it;
                }
            }
            else{
                if(*it - 1 == *next(it) || *it - 1 == *prev(it)){
                    if(best == l.end() || *best < *it)
                        best = it;
                }
            }
        }

        if(best != l.end()){
            ans++;
            l.erase(best);
        }
    }
    cout << ans << "\n";

    return 0;   
}
