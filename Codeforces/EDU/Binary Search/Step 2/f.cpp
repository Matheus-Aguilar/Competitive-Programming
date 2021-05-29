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
#define MAXN 200100

using namespace std;

string s, t, p;
int a[MAXN];

bool check(int m){
    
    s = t;

    for(int i = 0; i < m; i++)
        s[a[i] - 1] = '*';

    for(int i = 0, j = 0; i < s.size(); i++){
        if(s[i] == p[j]){

            j++;

            if(j == p.size())
                return true;
        }
    }

    return false;
}

int binSearch(int l, int r){
    
    while(l < r){
        
        int m = l + (r - l)/2;

        if(check(m))
            l = m + 1;
        else
            r = m;
    }
    
    return l - 1;
}

int main(){
    optimize;

    cin >> t >> p;

    for(int i = 0; i < t.size(); i++)
        cin >> a[i];

    cout << binSearch(0, t.size()) << "\n";
    
    return 0;   
}
