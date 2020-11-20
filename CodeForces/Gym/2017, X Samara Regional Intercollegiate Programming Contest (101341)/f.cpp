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
#define fi first
#define se second
 
using namespace std;
 
pair<char, char> query(int a, int b){
    pair<char, char> q;
    cout << "? " << a << " " << b << endl;
    cin >> q.fi >> q.se;
    return q;
}
 
int main(){
    
    //optimize;
 
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> ans;
    iota(all(a), 1);
 
    while(a.size() > 1){
        vector<int> b;
        for(int i = 0; i + 1 < a.size(); i += 2){
            pair<char, char> q = query(a[i], a[i + 1]);
            if(q.fi == q.se){
                if(q.fi == '+')
                    b.push_back(a[i]);
            }
            else{
                if(q.fi == '-')
                    b.push_back(a[i]);
                else
                    b.push_back(a[i + 1]);
            }
        }
        if(a.size() % 2){
            int ok = 0;
            for(int i = 0; i < b.size(); i++){
                pair<char, char> q = query(a.back(), b[i]);    
                if(q.se == '+')
                    ok++;
                else
                    ok--;
            }
            if(ok >= 0)
                b.push_back(a.back());
        }
        a = b;
    }
 
    for(int i = 1; i <= n; i++){
        if(a[0] != i){
            pair<char, char> q = query(a[0], i);
            if(q.fi == '+')
                ans.push_back(i);
        }
        else
            ans.push_back(i);
    }
 
    cout << "! " << ans.size() << " ";
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
 
    return 0;   
}