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
        vector<int> cont(n + 1, 0);
        set<int> s;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            s.insert(a);
            cont[a]++;
        }

        int max_repeat = *max_element(all(cont));
        int max_unique = s.size();

        if(max_repeat < max_unique)
            cout << max_repeat << "\n";
        else if(max_repeat == max_unique)
            cout << max_unique - 1 << "\n";
        else
            cout << max_unique << "\n";
    }

    return 0;   
}
