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

int query(int i, int j){
    
    int m;
    
    cout << "M " << i + 1 << " " << j + 1 << endl;
    cin >> m;

    if(m == -1)
        exit(0);

    return m - 1;
}

int swp(int i, int j){
    int s;
    
    cout << "S " << i + 1 << " " << j + 1 << endl;
    cin >> s;

    return s;
}

int ans(){

    int d;

    cout << "D" << endl;
    cin >> d;

    if(d == -1)
        exit(0);
    
    return d;
}

int main(){
    //optimize;

    int T, n;
    cin >> T >> n;

    for(int t = 1; t <= T; t++){
        
        for(int i = 0; i < n - 1; i++){
            int q = query(i, n - 1);
            if(i != q) 
                swp(i, q);
        }

        ans();
    }
    
    return 0;   
}
