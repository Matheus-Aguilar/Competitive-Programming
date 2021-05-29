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

void print(vector<int> &a){
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << " \n"[i==a.size()-1];
}

void solveMin(vector<int> &a){
    
    int q = -INF;
    vector<int> p(a.size());
    set<int> s;

    for(int i = 1; i <= a.size(); i++)
        s.insert(i);

    for(int i = 0; i < a.size(); i++){
        
        if(q < a[i]){
            p[i] = a[i];
            q = a[i];
        }
        else{
            p[i] = *s.begin();
        }

        s.erase(p[i]);
    }

    print(p);
}

void solveMax(vector<int> &a){
    
    int q = -INF;
    vector<int> p(a.size());
    set<int> s;

    for(int i = 1; i <= a.size(); i++)
        s.insert(i);

    for(int i = 0; i < a.size(); i++){
        
        if(q < a[i]){
            p[i] = a[i];
            q = a[i];
        }
        else{
            p[i] = *prev(s.upper_bound(q));
        }

        s.erase(p[i]);
    }

    print(p);
}

int main(){
    optimize;

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        solveMin(a);
        solveMax(a);
    }
    
    return 0;   
}
