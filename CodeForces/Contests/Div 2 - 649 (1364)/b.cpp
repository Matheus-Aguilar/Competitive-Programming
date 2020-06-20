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
        int n, a;
        cin >> n;

        ll sum = 0;
        vector<int> v;

        cin >> a;
        v.push_back(a);

        cin >> a;
        v.push_back(a);

        n -= 2;

        while(n--){
            cin >> a;
            int b = v.back();
            v.pop_back();
            int c = v.back();
            v.pop_back();

            if(abs(c - b) + abs(b - a) <= abs(c - a)){
                v.push_back(c);
                v.push_back(a);
            }
            else{
                v.push_back(c);
                v.push_back(b);
                v.push_back(a);
            }
        }

        cout << v.size() << "\n";
        for(int i = 0; i < v.size(); i++)
            cout << v[i] << " \n"[i == v.size() - 1];
    }

    return 0;   
}
