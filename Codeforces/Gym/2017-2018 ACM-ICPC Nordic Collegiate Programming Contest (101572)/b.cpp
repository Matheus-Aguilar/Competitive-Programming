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

struct Runner{
    string name;
    double a, b;

    bool operator<(const Runner &r){
        if(b != r.b) return b < r.b;
        if(a != r.a) return a < r.a;
        return name < r.name;
    }
};

double calc(array<int, 4> &a, vector<Runner> &v){
    return v[a[0]].a + v[a[1]].b + v[a[2]].b + v[a[3]].b;
}

bool cmp(array<int, 4> &a, array<int, 4> &b, vector<Runner> &v){
    return calc(a, v) > calc(b, v);
}

int main(){
    optimize;

    int n;
    cin >> n;

    vector<Runner> v(n);
    array<int, 4> best, val;

    best = {0, 1, 2, 3};

    for(int i = 0; i < n; i++){
        cin >> v[i].name >> v[i].a >> v[i].b;
    }

    sort(all(v));

    val = {1, 0, 2, 3};
    if(cmp(best, val, v)) 
        best = val;

    val = {2, 0, 1, 3};
    if(cmp(best, val, v)) 
        best = val;
    
    for(int i = 3; i < n; i++){
        val = {i, 0, 1, 2};
        if(cmp(best, val, v)) 
            best = val;    
    }

    cout << fixed << setprecision(2) << calc(best, v) << "\n";
    cout << v[best[0]].name << "\n";
    cout << v[best[1]].name << "\n";
    cout << v[best[2]].name << "\n";
    cout << v[best[3]].name << "\n";

    return 0;   
}
