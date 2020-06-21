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
    
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    
    int pos = -1;

    for(int i = 0; i < n; i++){
        if(v[i] == 0 || v[i] == 5){
            pos = i;
            if(v[n - 1] >= v[i])
                break;
        }
    }
    

    if(pos == -1)
        cout << pos << "\n";
    else{
        swap(v[n - 1], v[pos]);
        for(int i = 0; i < n; i++)
            cout << v[i] << " \n"[i == n - 1];
    }

    return 0;   
}
